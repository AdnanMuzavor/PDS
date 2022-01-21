/*
104. Maximum Depth of Binary Tree
Easy

5693

114

Add to List

Share
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
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
            int x = ht(root->right);
            int y = ht(root->left);
            return max(x, y) + 1;
        }
        return 0;
    }
    int maxDepth(TreeNode *root)
    {
        return ht(root);
    }
};