# A. Helpful Maths [Codeforces](https://codeforces.com/contest/339/problem/A)

## Problem Description

Xenia, a beginner in math, needs help arranging a sum of numbers in non-decreasing order. The sum on the board is given as a single string of numbers separated by the `+` symbol. The task is to rearrange these numbers so that they appear in ascending order, with `+` symbols placed between them, making it easier for Xenia to calculate.

### Input

- A non-empty string `s` representing the sum Xenia needs to count.
- `s` consists only of digits (`1`, `2`, `3`) and the `+` symbol.
- The string `s` is at most 100 characters long.

### Output

- Print the sum with numbers arranged in non-decreasing order, with `+` symbols between them.

### Examples

#### Example 1
**Input**:
```plaintext
3+2+1
```

**Output**:
```plaintext
1+2+3
```

#### Example 2
**Input**:
```plaintext
1+1+3+1+3
```

**Output**:
```plaintext
1+1+1+3+3
```

#### Example 3
**Input**:
```plaintext
2
```

**Output**:
```plaintext
2
```

### Solution Outline

1. **Extract the Numbers**:
   - Split the input string `s` by the `+` symbol to get a list of numbers.

2. **Sort the Numbers**:
   - Convert the extracted numbers to integers for easy sorting.
   - Sort the list in non-decreasing order.

3. **Reformat the Sum**:
   - Join the sorted numbers back together with the `+` symbol between them.

4. **Print the Result**:
   - Output the reformatted sum.

### Solution Code 'python'

```python
# Input string
s = input().strip()

# Step 1: Extract numbers as list of strings
numbers = s.split('+')

# Step 2: Sort the numbers
sorted_numbers = sorted(numbers)

# Step 3: Join the sorted numbers with '+' to create the desired output format
result = '+'.join(sorted_numbers)

# Step 4: Print the result
print(result)
```

### Explanation of Code

1. **Splitting the Input**: `s.split('+')` splits the string by the `+` symbol, resulting in a list of numbers.
2. **Sorting the Numbers**: `sorted(numbers)` sorts the list in ascending order.
3. **Rejoining the Sorted List**: `'+'.join(sorted_numbers)` joins the sorted numbers back into a single string with `+` symbols in between.

### Complexity Analysis

- **Time Complexity**: Sorting takes **O(n log n)** where `n` is the number of numbers in the sum.
- **Space Complexity**: **O(n)**, for storing the list of numbers and the sorted result.

### Edge Cases

- **Single Number**: If `s` contains only one number (e.g., "2"), no sorting or rejoining is needed.
- **Already Sorted Input**: If the input is already sorted, the output should be identical to the input.
- **All Same Numbers**: If all numbers are the same (e.g., "1+1+1"), the output remains the same.