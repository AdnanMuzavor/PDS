/*
101. Symmetric Tree
Easy

8393

204

Add to List

Share
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
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

// OPTIMISED APPROACH
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return helper(root->left, root->right);
}

bool helper(TreeNode *p, TreeNode *q)
{
    // If it's leaf node,thn it's always symmetric
    if (!p && !q)
        return true;
    // If one node exists and other doesn't
    if (!p || !q)
        return false;
    // Since we are sending left of 1na dright of other
    // Values are suppose to be equal
    if (p->val != q->val)
        return false;
    // If it crosses above conditions means
    // It;s syn now checking lower level
    return helper(p->left, q->right) && helper(p->right, q->left);
}
// BRUTE FORCE
class Solution
{
public:
    vector<int> pre;
    vector<int> pos;
    void pr(TreeNode *r)
    {
        if (r)
        {
            pre.push_back(r->val);
            pr(r->left);
            pr(r->right);
        }
        else
        {
            pre.push_back(0);
        }
    }
    void po(TreeNode *r)
    {
        if (r)
        {

            po(r->left);
            po(r->right);
            pos.push_back(r->val);
        }
        else
        {
            pos.push_back(0);
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root->left && !root->right)
        {
            return true;
        }
        pr(root->left);
        po(root->right);
        reverse(pos.begin(), pos.end());
        if (pos.size() != pre.size())
            return false;
        for (int i = 0; i < pos.size(); i++)
        {
            if (pre[i] != pos[i])
            {
                return false;
            }
        }
        return true;
    }
};