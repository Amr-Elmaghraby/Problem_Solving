# Invert Binary Tree

This repository contains the solution to the "Invert Binary Tree" problem from LeetCode.

## Problem Description

Given the root of a binary tree, invert the tree, and return its root.

### Example:

**Input:**

```
    4
   /   \
  2     7
 / \   / \
1   3 6   9
```

**Output:**

```
    4
   /   \
  7     2
 / \   / \
9   6 3   1
```

## Solution

The solution is implemented in C++ and can be found in the `invertBinaryTree.cpp` file. The main idea is to recursively swap the left and right children of each node in the binary tree.

### Code Explanation

- **Recursive Function:** The `Recursive` function swaps the left and right children of the given node and then recursively calls itself for the left and right children.
- **invertTree Function:** The `invertTree` function calls the `Recursive` function starting from the root of the tree.
- **Main Function:** The `main` function creates a binary tree, inverts it using the `invertTree` function, and then prints the level order traversal of the inverted tree.

### Usage

To run the solution, compile and execute the `invertBinaryTree.cpp` file. The program will output the level order traversal of the inverted binary tree.

```sh
g++ invertBinaryTree.cpp -o invertBinaryTree
./invertBinaryTree
```

## References

- [Invert Binary Tree on LeetCode](https://leetcode.com/problems/invert-binary-tree/)
