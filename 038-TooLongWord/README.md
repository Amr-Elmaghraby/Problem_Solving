# A. Way Too Long Words [Codeforces](https://codeforces.com/contest/71/problem/A)

## Problem Description

Some words, such as "localization" or "internationalization," are long enough to make writing them multiple times tedious. A word is considered **too long** if its length exceeds 10 characters. 

For words that are too long, you must create an **abbreviation**:
1. Write the **first letter** of the word.
2. Write the **number of characters** between the first and last letters.
3. Write the **last letter** of the word.

If a word is 10 characters or fewer, it remains unchanged.

### Input

The input consists of:
- An integer `n` (1 ≤ `n` ≤ 100) on the first line, representing the number of words.
- The next `n` lines each contain a single word consisting of lowercase Latin letters (length between 1 and 100 characters).

### Output

Print `n` lines. Each line should contain:
- The abbreviation of the word if it is too long (more than 10 characters).
- The word itself if it is not too long.

### Examples

#### Example 1
**Input**:
```plaintext
4
word
localization
internationalization
pneumonoultramicroscopicsilicovolcanoconiosis
```

**Output**:
```plaintext
word
l10n
i18n
p43s
```

**Explanation**:
1. "word" remains as it is (length ≤ 10).
2. "localization" becomes "l10n" (first letter `l`, last letter `n`, and 10 characters in between).
3. "internationalization" becomes "i18n" (first letter `i`, last letter `n`, and 18 characters in between).
4. "pneumonoultramicroscopicsilicovolcanoconiosis" becomes "p43s" (first letter `p`, last letter `s`, and 43 characters in between).

### Solution Outline

1. **Check Word Length**:
   - For each word, check if its length exceeds 10 characters.
   
2. **Generate Abbreviation**:
   - If the word length is more than 10, generate the abbreviation using:
     - The first character.
     - The count of intermediate characters.
     - The last character.
   
3. **Output Result**:
   - Print each transformed word (or the original if its length is ≤ 10).

### Edge Cases

- Words with exactly 10 characters remain unchanged.
- Words with fewer than or equal to 10 characters should not be abbreviated.