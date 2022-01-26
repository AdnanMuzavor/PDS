/*
257. Binary Tree Paths
Easy

3580

168

Add to List

Share
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.



Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
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
    vector<string> s1;
    void getpath(TreeNode *root, string s)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            s += to_string(root->val);
            s1.push_back(s);
            return;
        }

        s += to_string(root->val);
        getpath(root->left, s + "->");
        getpath(root->right, s + "->");
        return;
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        getpath(root, "");
        return s1;
    }
};