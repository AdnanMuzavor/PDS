/*
501. Find Mode in Binary Search Tree
Easy

1894

518

Add to List

Share
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
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
    map<int, int> m;
    int maxi = INT_MIN;
    void preorder(TreeNode *r)
    {
        if (r)
        {
            // Keeping track of occurence of each value
            m[r->val]++;
            // Get the mode value->i.e maximum occurence of any number
            maxi = max(maxi, m[r->val]);
            preorder(r->left);
            preorder(r->right);
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        vector<int> op;
        // If it's a single node
        // If you use thid code make sure you first try find element
        if (root && !root->left && !root->right)
            op.push_back(root->val);

        preorder(root);
        // putting those values in output whose occurence is maximum
        for (auto e : m)
        {
            if (e.second == maxi && find(op.begin(), op.end(), e.first) == op.end())
            {
                op.push_back(e.first);
            }
        }
        return op;
    }
};
