/*
110. Balanced Binary Tree
Easy

5061

277

Add to List

Share
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
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
//Less efficient way

class Solution
{
public:
    bool ans = true;
    int ht(TreeNode *r)
    {
        if (r)
        {
            // At each node get left height and right height
            int x = ht(r->left);
            int y = ht(r->right);
            // if diff brtween left and right node exceeds 1 set ans to false
            if (abs(x - y) > 1)
                ans = false;
            return max(x, y) + 1;
        }
        return 0;
    }
    bool isBalanced(TreeNode *root)
    {
        ht(root);
        return ans;
    }
};
//More efficent way
class Solution {
public:
    int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;
        
        int left=depth(root->left);
        int right=depth(root->right);
        
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
