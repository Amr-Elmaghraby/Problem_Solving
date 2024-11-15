# A. Free Ice Cream [Codeforces](https://codeforces.com/contest/686/problem/A)

## Problem Description

Kay and Gerda are giving away free ice cream to children during the summer. The queue consists of two types of people:
- **Carriers** who bring ice cream packs to Kay and Gerda.
- **Children** who want to take ice cream packs.

Kay and Gerda start with a certain number of ice cream packs. If a child requests ice cream and there are enough packs, they get the ice cream; otherwise, they leave distressed. Your task is to calculate:
1. The number of ice cream packs left after all operations.
2. The number of distressed children who couldn't get the ice cream they wanted.

### Input

- The first line contains two integers `n` and `x`, where:
  - `n` is the number of people in the queue (1 ≤ n ≤ 1000).
  - `x` is the initial number of ice cream packs (0 ≤ x ≤ 10^9).
- Each of the next `n` lines contains a character `+` or `-` followed by an integer `di`:
  - `+ di` means a carrier arrives with `di` ice cream packs.
  - `- di` means a child arrives and asks for `di` ice cream packs.

### Output

Print two space-separated integers:
1. The number of ice cream packs left after all operations.
2. The number of distressed children (children who couldn't get the ice cream they wanted).

### Examples

#### Example 1
**Input**:
```plaintext
5 7
+ 5
- 10
- 20
+ 40
- 20
```

**Output**:
```plaintext
22 1
```

**Explanation**:
- Initially, Kay and Gerda have 7 packs of ice cream.
- Carrier brings 5 more, now they have 12 packs.
- A child asks for 10 packs and receives them, 2 packs remain.
- Another child asks for 20 packs, but only 2 packs are available, so the child leaves distressed.
- A carrier brings 40 more, now they have 42 packs.
- A child asks for 20 packs, receives them, 22 packs remain.

#### Example 2
**Input**:
```plaintext
5 17
- 16
- 2
- 98
+ 100
- 98
```

**Output**:
```plaintext
3 2
```

**Explanation**:
- Initially, Kay and Gerda have 17 packs of ice cream.
- A child asks for 16 packs and gets them, 1 pack remains.
- Another child asks for 2 packs and gets them, no packs remain.
- A third child asks for 98 packs but there are none, so they leave distressed.
- A carrier brings 100 packs, now they have 100 packs.
- A child asks for 98 packs and receives them, leaving 3 packs remaining.

### Solution Outline

1. **Initial Setup**:
   - Start with the given number of ice cream packs `x`.
   - Initialize a counter for distressed children to 0.

2. **Process the Queue**:
   - Loop over each person in the queue:
     - If it's a carrier (`+ di`), add `di` packs to the current total.
     - If it's a child (`- di`), check if there are enough packs:
       - If yes, subtract `di` packs from the total.
       - If no, increase the distressed children counter.

3. **Output the Results**:
   - After processing all people, print the number of remaining ice cream packs and the number of distressed children.

### Solution Code

```python
# Read the first line
n, x = map(int, input().split())

# Initialize distressed children counter
distressed = 0

# Process each operation
for _ in range(n):
    operation, di = input().split()
    di = int(di)
    
    if operation == "+":
        # A carrier brings ice cream packs
        x += di
    elif operation == "-":
        # A child asks for ice cream packs
        if x >= di:
            x -= di
        else:
            distressed += 1

# Output the final results
print(x, distressed)
```

### Explanation of Code:
1. **Input Parsing**:
   - We first read the values of `n` (number of operations) and `x` (initial number of ice cream packs).
   - For each operation, we read the type (`+` or `-`) and the number of packs (`di`).

2. **Handling Operations**:
   - If the operation is `+`, we add the `di` packs to `x` (the total ice cream).
   - If the operation is `-`, we check if there are enough packs. If so, we subtract the requested number of packs from `x`. If not, we increase the `distressed` counter.

3. **Output**:
   - After processing all the operations, we print the remaining number of ice cream packs and the number of distressed children.

### Time Complexity:
- The time complexity is **O(n)**, where `n` is the number of operations, because we process each operation in constant time.

### Edge Cases:
- When there are no distressed children because enough ice cream is available.
- When no ice cream is available from the start (`x = 0`).
- When all the operations are carriers bringing ice cream, or all are children asking for ice cream.

