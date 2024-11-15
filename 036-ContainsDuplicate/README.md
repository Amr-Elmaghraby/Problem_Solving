
# Contains Duplicate [Leetcode](https://leetcode.com/problems/contains-duplicate/description/)

## Problem Description
### problem Number 271 Easy

Given an integer array `nums`, determine if any value appears at least twice in the array. If any element has duplicates, return `true`; if all elements are unique, return `false`.
## Difficulty
Easy

---

### Example

#### Example 1
**Input**:
```plaintext
nums = [1,2,3,1]
```

**Output**:
```plaintext
true
```

**Explanation**: The element `1` appears twice (at indices `0` and `3`).

#### Example 2
**Input**:
```plaintext
nums = [1,2,3,4]
```

**Output**:
```plaintext
false
```

**Explanation**: All elements are distinct.

#### Example 3
**Input**:
```plaintext
nums = [1,1,1,3,3,4,3,2,4,2]
```

**Output**:
```plaintext
true
```

### Constraints

- \(1 \leq \text{nums.length} \leq 10^5\)
- \( -10^9 \leq \text{nums}[i] \leq 10^9 \)

### Solution Outline

1. **Check for Duplicates**:
   - Use a data structure to track seen elements as we iterate through `nums`.
   - If an element is encountered that has already been seen, return `true`.
   - If we reach the end of the list without duplicates, return `false`.

2. **Efficiency**:
   - The solution should be efficient, ideally O(n) time complexity and O(n) space complexity for storing elements seen so far.

