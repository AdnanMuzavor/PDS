/*
404. Sum of Left Leaves
Easy

2969

234

Add to List

Share
Given the root of a binary tree, return the sum of all left leaves.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
Example 2:

Input: root = [1]
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;

    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val, TreeNode *_left, TreeNode *_right, TreeNode *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    int sum = 0;
    // one is node and other is bool a which helps in classfying node direction
    // a is true means left else right
    void leftleaf(TreeNode *r, bool a)
    {
        // if null thn return
        if (!r)
            return;
        // if leaf and it's left sided node thn add to sum
        if (!r->left && !r->right && a)
            sum += r->val;
        // else call for left and right sided nodes
        leftleaf(r->left, true);
        leftleaf(r->right, false);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return 0;
        leftleaf(root, false);
        return sum;
    }
};
