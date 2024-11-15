# A. Anton and Letters [Codeforces](https://codeforces.com/contest/443/problem/A)

## Problem Description

Anton has found a set of lowercase English letters, which he wrote out as a single line in a specific format:
- The set is enclosed in curly braces `{}`.
- Each letter is separated by a comma and a space (`, `).
  
Anton may have repeated some letters by mistake, so your task is to count the **distinct** letters in this set.

### Input

The input is a single line containing the set of letters, formatted as follows:
- Starts with `{` and ends with `}`.
- Inside, letters are listed in lowercase, separated by `, `.
  
The line length will not exceed 1000 characters.

### Output

Print a single integer representing the number of distinct letters in Anton's set.

### Examples

#### Example 1
**Input**:
```plaintext
{a, b, c}
```

**Output**:
```plaintext
3
```

**Explanation**: There are three distinct letters: `a`, `b`, and `c`.

#### Example 2
**Input**:
```plaintext
{b, a, b, a}
```

**Output**:
```plaintext
2
```

**Explanation**: There are two distinct letters: `a` and `b`.

#### Example 3
**Input**:
```plaintext
{}
```

**Output**:
```plaintext
0
```

**Explanation**: The set is empty, so there are zero distinct letters.

### Solution Outline

1. **Extract Letters**:
   - Remove the curly braces and split the contents by `, ` to get individual letters.
   
2. **Store Unique Letters**:
   - Use a set to store the letters, as sets automatically handle duplicates.

3. **Count and Output**:
   - The size of the set will represent the number of distinct letters.

### Edge Cases

- An empty set `{}` should return `0`.
- Input with repeated letters, such as `{a, a, a}`, should count `a` only once.