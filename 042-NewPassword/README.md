
# Problem Statement: New Password [codeforces](https://codeforces.com/contest/770/problem/A)

Innokentiy wants to change his password on the social network "Contact!" but finds it tedious to create a new one himself. He needs help to generate a password that meets the following requirements:

1. **Password Length**: The password must be exactly `n` characters long.
2. **Character Set**: The password should contain only lowercase Latin letters (i.e., letters from `a` to `z`).
3. **Distinct Characters**: The password must include exactly `k` distinct characters.
4. **No Consecutive Repeats**: No two consecutive characters in the password should be the same.

Your task is to help Innokentiy by creating a password that satisfies all of these conditions.

### Input Format
- A single line containing two integers, `n` and `k`:
  - `n` (2 ≤ `n` ≤ 100): The desired length of the password.
  - `k` (2 ≤ `k` ≤ min(`n`, 26)): The number of distinct characters the password should contain.

**Note**: There is always a valid password that meets these conditions.

### Output Format
- Print a single line containing any valid password that satisfies the conditions outlined above.

### Examples

#### Input
```
7 3
```

#### Output
```
abcabca
```

#### Input
```
4 2
```

#### Output
```
xixi
```

#### Input
```
6 6
```

#### Output
```
python
```

*(Note: The outputs are just one example of a valid password. Other valid outputs are possible as long as they meet the requirements.)*



