# A. Carrot Cakes [Codeforces](https://codeforces.com/contest/799/problem/A)

## Problem Description

In a game by Playrix, Arkady needs to bake at least `n` carrot cakes to complete a task. The game mechanics are as follows:

- **Baking Time**: It takes `t` minutes for a single oven to bake `k` cakes, and all `k` cakes are ready simultaneously after `t` minutes.
- **Oven Count**: Initially, Arkady has only one oven. He has the option to build a second oven, which takes `d` minutes to complete. Once built, both ovens can bake cakes simultaneously.
- **Goal**: Determine whether building the second oven reduces the minimum time needed to bake `n` cakes. If building the oven does not reduce the time or makes it the same as using one oven, it is deemed unnecessary to build.

### Input

The input consists of four integers:

1. `n` — the number of cakes Arkady needs.
2. `t` — the time (in minutes) required by one oven to bake `k` cakes.
3. `k` — the number of cakes baked by one oven in one batch.
4. `d` — the time required to build the second oven.

Constraints:
- \(1 \leq n, t, k, d \leq 1000\)

### Output

Print `"YES"` if building the second oven decreases the minimum time needed to bake the required `n` cakes. Otherwise, print `"NO"`.

### Examples

#### Example 1
**Input**:
```
8 6 4 5
```

**Output**:
```
YES
```

**Explanation**:
- With one oven, 8 cakes are completed in 12 minutes.
- The second oven could be ready in 5 minutes, allowing the first oven to bake 4 cakes in 6 minutes, and the second oven to bake the remaining 4 cakes by 11 minutes.
- Therefore, building the second oven reduces the time, so the output is "YES".

#### Example 2
**Input**:
```
8 6 4 6
```

**Output**:
```
NO
```

**Explanation**:
- Both scenarios (one or two ovens) require 12 minutes to bake the 8 cakes.
- Building the second oven does not reduce the baking time, so the output is "NO".

#### Example 3
**Input**:
```
10 3 11 4
```

**Output**:
```
NO
```

**Explanation**:
- The single oven can bake all 10 cakes in 3 minutes, faster than the time needed to build the second oven.
- Hence, it is unnecessary to build the second oven, and the output is "NO".

#### Example 4
**Input**:
```
4 2 1 4
```

**Output**:
```
YES
```

### Notes

To solve this problem, consider:
- The time required by one oven alone to bake `n` cakes.
- The time required if Arkady builds a second oven and uses both ovens to complete the task.
- If building the second oven allows Arkady to bake the required cakes faster than one oven alone, output "YES"; otherwise, output "NO".

