/*
543. Diameter of Binary Tree
Easy

6939

427

Add to List

Share
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int ht(TreeNode *root)
    {
        if (root)
        {
            int lh = ht(root->left);
            int rh = ht(root->right);
            return max(lh, rh) + 1;
        }
        return 0;
    }
    int d = INT_MIN;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root || (!root->left && !root->right))
        {
            return 0;
        }

        d = max(ht(root->left) + ht(root->right), d);

        diameterOfBinaryTree(root->left),

            diameterOfBinaryTree(root->right);

        return d;
    }
};
