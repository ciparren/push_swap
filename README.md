*This project has been created as part of the 42 curriculum by ciparren and gamercha.*

---

# push_swap

> **Because Swap_push doesn't feel as natural.**

Sort a stack of integers using the minimum number of operations — with only two stacks and eleven allowed moves.

---

## Table of Contents

- [Description](#description)
- [Instructions](#instructions)
- [Operations Reference](#operations-reference)
- [Algorithm Design](#algorithm-design)
  - [Disorder Metric](#disorder-metric)
  - [Strategy Selection](#strategy-selection)
  - [Simple — O(n²)](#simple--on)
  - [Medium — O(n√n)](#medium--onn)
  - [Complex — O(n log n)](#complex--on-log-n)
  - [Adaptive](#adaptive)
- [Performance Benchmarks](#performance-benchmarks)
- [Benchmark Mode](#benchmark-mode)
- [Error Management](#error-management)
- [Resources](#resources)

---

## Description

**push_swap** is an algorithmics project: given a list of integers loaded into stack A, the program must output the shortest possible sequence of Push_swap operations to sort them in ascending order.

The challenge is not just to sort — it is to sort *efficiently*, using only two stacks and eleven operations. This forces a rigorous understanding of algorithmic complexity in a very concrete, measurable way.

The program implements **four distinct sorting strategies**, selects among them at runtime based on a computed disorder metric, and exposes a benchmark mode for analysis.

```
Input:  ./push_swap 3 1 4 2 5
Output: pb
        pb
        solve_three on remaining...
        pa
        pa
        (sequence of operations printed to stdout)
```

---

## Instructions

### Requirements

| Requirement | Detail |
|---|---|
| Language | C |
| Norm | 42 Norm compliant |
| Compiler flags | `-Wall -Wextra -Werror` |
| External functions | `read`, `write`, `malloc`, `free`, `exit` |
| Library | libft (included in `ft_libc/`) |

### Compilation

```bash
# Build push_swap
make

# Rebuild from scratch
make re

# Clean objects
make clean

# Clean everything including binary
make fclean
```

### Usage

```bash
# Basic usage — separate arguments
./push_swap 3 1 4 2 5

# Using a quoted string
./push_swap "3 1 4 2 5"

# Force a specific strategy
./push_swap --simple   3 1 4 2 5
./push_swap --medium   3 1 4 2 5
./push_swap --complex  3 1 4 2 5
./push_swap --adaptive 3 1 4 2 5   # default

# Benchmark mode (metrics sent to stderr)
./push_swap --bench 3 1 4 2 5

# Count operations generated
./push_swap 3 1 4 2 5 | wc -l

# Verify correctness with the checker
ARG="3 1 4 2 5"; ./push_swap $ARG | ./checker_linux $ARG
```

### Strategy Flags

| Flag | Algorithm | Complexity |
|---|---|---|
| `--simple` | Bubble sort | O(n²) |
| `--medium` | Chunk sort | O(n√n) |
| `--complex` | Radix sort | O(n log n) |
| `--adaptive` | Auto-select by disorder | O(n) / O(n√n) / O(n log n) |

If no flag is given, `--adaptive` is the default.

---

## Operations Reference

| Operation | Description |
|---|---|
| `sa` | Swap top 2 elements of stack A |
| `sb` | Swap top 2 elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B onto A |
| `pb` | Push top of A onto B |
| `ra` | Rotate A upward (top becomes bottom) |
| `rb` | Rotate B upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (bottom becomes top) |
| `rrb` | Reverse rotate B |
| `rrr` | `rra` and `rrb` simultaneously |

### Visual example — sorting `2 1 3 6 5 8`

```
Init:       sa:         pb pb pb:     ra rb (=rr):   rra rrb (=rrr):  sa:         pa pa pa:
  2           1           6   3         5   2           6   3           5   3         1
  1           2           5   2         8   1           5   2           6   2         2
  3           3           8   1         6   3           8   1           8   1         3
  6           6        A     B       A     B         A     B         A     B         5
  5           5                                                                      6
  8           8                                                                      8
```

Result: sorted in 12 operations.

---

## Algorithm Design

### Disorder Metric

Before choosing a strategy, the program computes a **disorder score** between `0.0` and `1.0` that measures how far stack A is from sorted order.

The score counts all pairs `(i, j)` where element `i` appears before element `j` in the stack but has a greater value (an inversion), divided by the total number of pairs:

```
disorder = number_of_inversions / total_pairs
```

| Disorder value | Meaning |
|---|---|
| `0.0` | Already perfectly sorted |
| `0.0 – 0.2` | Nearly sorted, few inversions |
| `0.2 – 0.5` | Moderately disordered |
| `0.5 – 1.0` | Highly disordered |
| `1.0` | Fully reversed (worst case) |

**Implementation** (`disorder.c`):

```c
float compute_disorder(t_stack *a) {
    for each pair (i, j) with i before j in the stack:
        total_pairs++
        if value[i] > value[j]:
            mistakes++
    return (float)mistakes / (float)total_pairs
}
```

> The disorder is computed **before any moves are made**, on the original input.

---

### Strategy Selection

```
START: compute_disorder(A)
            │
            ▼
    strategy flag given?
    ┌────── YES ──────┐
    │                 │  NO → ADAPTIVE
    ▼                 ▼
 force it       disorder < 0.2?
                ├── YES → bubblesort  O(n²)
                │
                └── NO → disorder < 0.5?
                          ├── YES → chunksort  O(n√n)
                          └── NO  → radix sort O(n log n)
```

**Threshold justification:**

| Disorder range | Strategy | Rationale |
|---|---|---|
| `< 0.2` | Bubble sort O(n²) | Few inversions → few swaps needed, constant overhead is low |
| `0.2 – 0.5` | Chunk sort O(n√n) | Moderate disorder → chunk partitioning balances push/rotate cost |
| `≥ 0.5` | Radix sort O(n log n) | High disorder → guaranteed logarithmic bound regardless of distribution |

For `n ≤ 5`, hardcoded optimal solutions are used regardless of disorder — the overhead of computing disorder is not justified for inputs this small.

---

### Simple — O(n²)

**Bubble sort adaptation** (`simple.c`)

**Small inputs — hardcoded optimal solutions:**

| Size | Function | Max operations |
|---|---|---|
| 1 | — | 0 |
| 2 | `solve_two` | 1 |
| 3 | `solve_three` | 2 |
| 4 | `solve_four` | ≤ 8 |
| 5 | `solve_five` | ≤ 12 |

**solve_three — all 6 permutations:**

| Index order | Operations |
|---|---|
| `[0, 1, 2]` | *(nothing)* |
| `[1, 0, 2]` | `sa` |
| `[2, 1, 0]` | `sa`, `rra` |
| `[2, 0, 1]` | `ra` |
| `[1, 2, 0]` | `sa`, `ra` |
| `[0, 2, 1]` | `rra` |

**solve_four / solve_five strategy:**

```
pb (×1 or ×2)          push smallest(s) to B
solve_three             sort remaining 3 in A optimally
rotate A to min=top     ensure index 0 is at top
find_and_insert (×1/2)  reinsert B elements in correct position
```

**Large inputs with low disorder:** standard bubble sort — compare adjacent elements with `sa`, advance with `ra`, repeat until `is_sorted()`.

**Complexity:** n elements × n passes = O(n²) operations.

---

### Medium — O(n√n)

**Chunk sort** (`medium.c`)

Divides the index space `[0, n-1]` into chunks of size `√n × 1.5`, pushes elements chunk by chunk to B, then pulls them back in descending order.

**Phase 1 — chunksort:**

```
chunk_size = floor(√n × 1.5)

i = 0
while A is not empty:
    if top of A has index ≤ i + chunk_size:
        pb                          ← element belongs to current chunk
        if top of B index ≤ i:
            rb                      ← sink older chunk elements in B
        i++
    else:
        ra                          ← not yet, keep looking
```

**Phase 2 — back_to_a:**

```
while B is not empty:
    find position of maximum index in B
    rotate B (shortest direction) to bring it to top
    pa
```

Since we always pull the maximum from B, A fills from largest to smallest → sorted ascending with smallest at top.

**Why `× 1.5`?**

With chunk size = √n: scanning A costs O(n / chunk) rotations per element = O(√n) rotations per element = O(n√n) total. The `1.5` factor is empirical tuning — it reduces rotations in A at the cost of slightly more work in B, producing better real-world results around 700–900 ops for n=100.

**Complexity:** O(n√n) pushes + O(n√n) rotations = O(n√n).

---

### Complex — O(n log n)

**LSD Radix sort** (`complex.c`)

Works on the **index** of each element (0 to n-1), not the original values. Using normalized indices ensures clean binary representation.

**Algorithm:**

```
max_bits = ceil(log2(n))

for bit i from 0 (LSB) to max_bits-1:
    for each of the n elements in A:
        if bit i of top element's index == 0:
            pb          ← bit is 0, goes to B
        else:
            ra          ← bit is 1, stays rotated in A
    pa all elements from B back to A
```

**Bit extraction:**

```c
(index >> i) & 1
```

`>> i` shifts the index right by `i` positions, bringing bit `i` to position 0. `& 1` masks everything else, leaving exactly `0` or `1`.

**Worked example — n=4 (indices 0–3):**

| Index | Binary (bit1 bit0) | Bit 0 | Bit 1 |
|---|---|---|---|
| 0 | `00` | 0 → pb | 0 → pb |
| 1 | `01` | 1 → ra | 0 → pb |
| 2 | `10` | 0 → pb | 1 → ra |
| 3 | `11` | 1 → ra | 1 → ra |

After pass 0: elements with bit0=0 are in B (0,2), bit0=1 are in A (1,3). After `pa` all. After pass 1: sorted.

**Complexity:** `log2(n)` passes × n operations per pass = O(n log n).

---

### Adaptive

**Disorder-driven auto-selection** (`adaptive.c`)

```c
void solve_adaptive(t_info *info) {
    if      (info->disorder < 0.2f)  bubblesort(info);    // O(n²)
    else if (info->disorder < 0.5f)  solve_medium(info);  // O(n√n)
    else                             raddix(info);         // O(n log n)
}
```

This is the default when no flag is given. The benchmark output always reports `Adaptative` as the strategy name when this mode is active, regardless of the internal algorithm chosen.

---

## Performance Benchmarks

### n = 100

| Result | Rating |
|---|---|
| < 700 ops | ⭐⭐⭐⭐⭐ Excellent |
| < 900 ops | ⭐⭐⭐⭐ |
| < 1100 ops | ⭐⭐⭐ |
| < 1300 ops | ⭐⭐ |
| < 1500 ops | ⭐ |
| ≥ 1500 ops | ❌ Fail |

### n = 500

| Result | Rating |
|---|---|
| < 5500 ops | ⭐⭐⭐⭐⭐ Excellent |
| < 7000 ops | ⭐⭐⭐⭐ |
| < 8500 ops | ⭐⭐⭐ |
| < 10000 ops | ⭐⭐ |
| < 11500 ops | ⭐ |
| ≥ 11500 ops | ❌ Fail |

### Testing commands

```bash
# Single test — 100 elements
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

# Single test — 500 elements
ARG=$(shuf -i 0-9999 -n 500 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

# Loop — 20 random tests of 100 elements
for i in $(seq 1 20); do
    ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    RES=$(./push_swap $ARG | ./checker_linux $ARG)
    echo "[$OPS ops] $RES"
done
```

---

## Benchmark Mode

The `--bench` flag prints metrics to `stderr` after sorting. The operation stream on `stdout` is unaffected, so checker still works normally.

```bash
# Run with benchmark, hide ops, show only metrics
ARG="4 67 3 87 23"
./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt
```

**Example output:**

```
[bench] disorder: 40.00%
[bench] strategy: Adaptative / O(n√n)
[bench] total_ops: 13
[bench] sa: 0  sb: 0  ss: 0  pa: 5  pb: 5
[bench] ra: 2  rb: 1  rr: 0  rra: 0  rrb: 0  rrr: 0
```

| Field | Description |
|---|---|
| `disorder` | Percentage of inverted pairs in the original input |
| `strategy` | Strategy name and complexity class |
| `total_ops` | Total number of operations generated |
| `sa` – `rrr` | Count of each individual operation type |

---

## Error Management

The program writes `Error\n` to `stderr` and exits with code 1 in the following cases:

| Case | Example input | Output |
|---|---|---|
| Non-integer argument | `./push_swap abc` | `Error` |
| Duplicate value | `./push_swap 1 2 1` | `Error` |
| Value out of INT range | `./push_swap 2147483648` | `Error` |
| No arguments | `./push_swap` | *(nothing, prompt returns)* |

```bash
$ ./push_swap abc
Error
$ ./push_swap 1 2 1
Error
$ ./push_swap 2147483648
Error
$ ./push_swap
$
```

---

## Resources

### Algorithmic references

| Resource | Topic |
|---|---|
| [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) | LSD radix sort explanation and complexity |
| [Bubble Sort — Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort) | Bubble sort fundamentals |
| [Kendall tau distance](https://en.wikipedia.org/wiki/Kendall_tau_distance) | Theory behind the disorder / inversion metric |
| [Big-O Cheat Sheet](https://www.bigocheatsheet.com/) | Complexity class quick reference |
| Knuth, *The Art of Computer Programming* Vol. 3 | Sorting and searching algorithms |

### AI usage

AI (Claude, Anthropic) was used throughout this project for the following tasks:

| Task | Description |
|---|---|
| Algorithm design review | Reviewing correctness of radix, chunk sort, and bubble sort adaptations |
| Complexity analysis | Verifying that each strategy's operation count falls within its claimed Big-O class |
| Bug diagnosis | Tracing specific inputs through algorithms to identify incorrect behavior |
| Code refactoring | Reducing function lengths to comply with the 42 Norm (max 25 lines per function) |
| README writing | Structuring and drafting this document |

All AI-generated content was reviewed, tested, and understood by both authors before inclusion. No code was used without full comprehension — both learners can explain and defend every function in the project.

---
