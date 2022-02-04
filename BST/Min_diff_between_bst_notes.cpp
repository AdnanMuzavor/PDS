/*
783. Minimum Distance Between BST Nodes
Easy

1479

303

Add to List

Share
Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.



Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
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

//BRUTE FORCE
class Solution
{
public:
    vector<int> v;
    vector<int> v;
    void pre(TreeNode *t)
    {
        if (t)
        {
            pre(t->left);
            v.push_back(t->val);
            pre(t->right);
        }
    }

    int minDiffInBST(TreeNode *root)
    {
        pre(root);
        sort(v.begin(), v.end());
        int d = INT_MAX;
        for (int i = 1; i < v.size(); i++)
        {
            d = min(d, v[i] - v[i - 1]);
        }
        return d;
    }
};
//OPTIMISED
class Solution
{
public:
    int res = INT_MAX, pre = -1;
    int minDiffInBST(TreeNode *root)
    {
        if (root->left != NULL)
            minDiffInBST(root->left);
        if (pre >= 0)
            res = min(res, root->val - pre);
        pre = root->val;
        if (root->right != NULL)
            minDiffInBST(root->right);
        return res;
    }
};
