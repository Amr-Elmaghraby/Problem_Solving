
# Convert Date to Binary [Leetcode](https://leetcode.com/problems/convert-date-to-binary/description/)

## Problem Description

You are given a string `date` representing a Gregorian calendar date in the format `yyyy-mm-dd`. The goal is to convert this date to its binary representation by:

1. Converting the year, month, and day separately into binary numbers.
2. Concatenating the binary values in the order of `year-month-day` without any leading zeroes.

Return the final binary representation of the date as a string.

### Example

#### Example 1
**Input**: 
```plaintext
date = "2080-02-29"
```

**Output**: 
```plaintext
"100000100000-10-11101"
```

**Explanation**:  
- Year `2080` in binary is `100000100000`
- Month `02` in binary is `10`
- Day `29` in binary is `11101`
  
Concatenate these binary representations to get `100000100000-10-11101`.

#### Example 2
**Input**:
```plaintext
date = "1900-01-01"
```

**Output**: 
```plaintext
"11101101100-1-1"
```

**Explanation**:  
- Year `1900` in binary is `11101101100`
- Month `01` in binary is `1`
- Day `01` in binary is `1`
  
Concatenate to form `11101101100-1-1`.

## Constraints

- `date.length == 10`
- `date[4] == date[7] == '-'`, and all other `date[i]` values are digits.
- The input represents a valid Gregorian date between `1900-01-01` and `2100-12-31` (inclusive).

## Solution Outline

1. **Extract Date Components**: Split the `date` string to retrieve `year`, `month`, and `day` components.
2. **Convert to Binary**:
   - Convert `year`, `month`, and `day` to integers.
   - Convert each integer to a binary representation using Python's `bin()` function, removing the '0b' prefix.
3. **Concatenate and Return**: Join the binary values with hyphens in the `year-month-day` format and return the result.

### Example Code (Python)

```python
def date_to_binary(date: str) -> str:
    year, month, day = date.split('-')
    
    year_bin = bin(int(year))[2:]
    month_bin = bin(int(month))[2:]
    day_bin = bin(int(day))[2:]
    
    return f"{year_bin}-{month_bin}-{day_bin}"
```

### Complexity Analysis

- **Time Complexity**: O(1), as the operation involves a fixed amount of string manipulation and conversion operations.
- **Space Complexity**: O(1), as only a fixed number of variables are used regardless of the input size.

## Usage

To use this function:
1. Place the code in a Python script or function.
2. Call `date_to_binary("yyyy-mm-dd")` with a valid `date` string as per the constraints.

