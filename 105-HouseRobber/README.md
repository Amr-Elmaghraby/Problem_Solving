# House Robber Problem

This repository contains the solution to the House Robber problem. 

## Problem Description

The House Robber problem is a classic dynamic programming problem where the goal is to determine the maximum amount of money that can be robbed from a series of houses without robbing two adjacent houses.

## Problem Link

You can find the problem description on LeetCode: [House Robber](https://leetcode.com/problems/house-robber/)

## Solution

The solution is implemented in `MaxMoneyRob.cpp`. The main idea is to use dynamic programming to keep track of the maximum amount of money that can be robbed up to each house, without robbing two adjacent houses.

## Usage

To run the solution, compile and execute the `MaxMoneyRob.cpp` file. The example vector of house money values is provided in the `main` function.

```cpp
g++ MaxMoneyRob.cpp -o MaxMoneyRob
./MaxMoneyRob
```

## Example

Given the vector of house money values:

```cpp
vector<int> nums = {1, 2, 134, 4, 2, 21, 4, 42, 123, 14, 10};
```

The output will be the maximum amount of money that can be robbed without robbing two adjacent houses.

## License

This project is licensed under the MIT License.