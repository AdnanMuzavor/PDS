/*
105. Construct Binary Tree from Preorder and Inorder Traversal
Medium

7481

190

Add to List

Share
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
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
    unordered_map<int, int> m;
    int i = 0;
    TreeNode *tree(vector<int> &pre, vector<int> &in, int l, int u)
    {
        // leaf node case
        if (l > u)
            return NULL;

        // Creating node which is located first in preorder
        // Thn incrementing i i.e i++ for next call
        TreeNode *res = new TreeNode(pre[i++]);

        // If it's only node in subtree
        if (l == u)
            return res;

        // Finding position of value whose node in created
        // in inorder array for to separate out left and right subtree
        // using upper and lower bound
        int mid = m[res->val];

        // Dividing as per subtrees
        res->left = tree(pre, in, l, mid - 1);
        res->right = tree(pre, in, mid + 1, u);
        return res;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        // Maping inorder elemets with indices to set ub and lb later
        for (int i = 0; i < inorder.size(); i++)
        {
            m[inorder[i]] = i;
        }
        return tree(preorder, inorder, 0, preorder.size() - 1);
    }
};