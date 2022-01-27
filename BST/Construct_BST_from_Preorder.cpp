/*
1008. Construct Binary Search Tree from Preorder Traversal
Medium

3215

58

Add to List

Share
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.



Example 1:


Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
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
    TreeNode *construct(vector<int> v, int l, int u)
    {

        if (l > u)
            return NULL;
        TreeNode *r = new TreeNode(v[l]);
        if (l == u)
            return r;
        int i = l + 1;
        while (i <= u && v[i] < r->val)
        {
            i++;
        }

        r->left = construct(v, l + 1, i - 1);

        r->right = construct(v, i, u);

        return r;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return construct(preorder, 0, preorder.size() - 1);
    }
};