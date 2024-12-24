# Permutation in String

This repository contains a C++ solution to the LeetCode problem "567. Permutation in String". The solution uses a sliding window approach to efficiently determine if a permutation exists.

The problem statement can be found [here](https://leetcode.com/problems/permutation-in-string/).
This repository contains a C++ solution to the problem of checking if one string is a permutation of another string within a given string. The solution uses a sliding window approach to efficiently determine if a permutation exists.

## Problem Statement

Given two strings `s1` and `s2`, write a function to return true if `s2` contains a permutation of `s1`. In other words, one of the first string's permutations is the substring of the second string.

## Solution

The solution is implemented in the `permutationInString.cpp` file. The main idea is to use a sliding window to compare the frequency of characters in the current window of `s2` with the frequency of characters in `s1`.

### Algorithm

1. Calculate the frequency of each character in `s1`.
2. Use a sliding window of size equal to the length of `s1` to traverse `s2`.
3. For each position in `s2`, update the frequency of characters in the current window.
4. Compare the frequency of characters in the current window with the frequency of characters in `s1`.
5. If they match, return true.
6. If the end of `s2` is reached without finding a match, return false.

### Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2)
        {
            return false;
        }

        vector<int> freq1(26, 0), freq2(26, 0);
        for (char c : s1)
        {
            ++freq1[c - 'a'];
        }
        // Sliding Window
        for (int i = 0; i < n2; ++i)
        {
            ++freq2[s2[i] - 'a'];

            if (i >= n1)
            {
                --freq2[s2[i - n1] - 'a'];
            }

            if (freq1 == freq2)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    string s1 = "adc";
    string s2 = "dcda";
    Solution sol;
    std::cout << sol.checkInclusion(s1, s2);
    return 0;
}
```

### Usage

To compile and run the program, use the following commands:

```sh
g++ -o permutationInString permutationInString.cpp
./permutationInString
```

### Example

For the input strings `s1 = "adc"` and `s2 = "dcda"`, the output will be `1` (true), indicating that `s2` contains a permutation of `s1`.

## License

This project is licensed under the MIT License.