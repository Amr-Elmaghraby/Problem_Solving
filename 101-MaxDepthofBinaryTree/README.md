# Maximum Depth of Binary Tree

This repo contains solutions to the "Maximum Depth of Binary Tree" problem from LeetCode. The problem can be solved using both iterative and recursive approaches. Below are the details of the two implementations provided in this repository.

## Problem Description

Given the `root` of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

## Files

### 1. `MAXDEPTHWITHOUTRECURSION.CPP`

This file contains the iterative solution to find the maximum depth of a binary tree using a level-order traversal (BFS).

#### Key Points:
- Uses a queue to traverse the tree level by level.
- Increments the depth for each level of nodes processed.

### 2. `MAXDEPTHRECURSION.CPP`

This file contains the recursive solution to find the maximum depth of a binary tree.

#### Key Points:
- Uses a helper function `Recursion` to recursively calculate the depth of left and right subtrees.
- Returns the maximum depth by comparing the depths of the left and right subtrees.

## Usage

To compile and run the programs, use the following commands:

```sh
g++ MAXDEPTHWITHOUTRECURSION.CPP -o maxDepthWithoutRecursion
./maxDepthWithoutRecursion
```

```sh
g++ MAXDEPTHRECURSION.CPP -o maxDepthRecursion
./maxDepthRecursion
```

## References

- [LeetCode Problem - Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
