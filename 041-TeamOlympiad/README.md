# A. Team Olympiad [Codeforces](https://codeforces.com/contest/490/problem/A)

## Problem Description

In a school, each student is good at exactly one subject out of programming, math, and physical education (PE). We know which subject each student excels in, given by a list of integers. The goal is to form the maximum number of teams, where each team consists of exactly three students, each with a unique skill.

A valid team must include:
1. One student good at programming.
2. One student good at math.
3. One student good at PE.

The task is to find the maximum number of such teams and output the indices of students in each team.

### Input

- The first line contains an integer `n` (1 ≤ n ≤ 5000) — the number of students.
- The second line contains `n` integers `t1, t2, ..., tn`, where each `ti` (1 ≤ ti ≤ 3) describes the skill of the i-th student:
  - `1` represents programming
  - `2` represents math
  - `3` represents PE

### Output

- The first line should contain an integer `w` — the maximum number of teams that can be formed.
- If `w > 0`, the following `w` lines should each contain three integers, representing the indices of students in each team.

### Example

#### Example 1
**Input**:
```plaintext
7
1 3 1 3 2 1 2
```

**Output**:
```plaintext
2
3 5 2
6 7 4
```

#### Example 2
**Input**:
```plaintext
4
2 1 1 2
```

**Output**:
```plaintext
0
```

### Solution Outline

1. **Identify Student Groups**: Traverse the list and group student indices by their skills:
   - Store indices for programming, math, and PE students separately.

2. **Calculate Maximum Teams**: Find the minimum count among the three groups (programming, math, PE), which will be the maximum number of teams possible.

3. **Form Teams**: Take students from each group up to the minimum count, and form a team for each set of three indices.

4. **Output the Results**: Print the maximum number of teams and each team’s indices.

### Complexity Analysis

- **Time Complexity**: **O(n)** for traversing the list and categorizing students.
- **Space Complexity**: **O(n)** for storing indices in separate lists for each skill type.

### Edge Cases

- **Not Enough Students for a Team**: If any skill group is empty or too small to form a team, output `0`.
- **All Students Have the Same Skill**: If all students belong to a single skill type, no teams can be formed, so output `0`.