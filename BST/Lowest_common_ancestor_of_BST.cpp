/*
235. Lowest Common Ancestor of a Binary Search Tree
Easy

4801

167

Add to List

Share
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”



Example 1:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:


Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [2,1], p = 2, q = 1
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
// 3 ways, method same but just extra code lines
// 1st effective way((95%))
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left
                                  : root;
}

// 2nd effective way((77%))
TreeNode *lowestCommonAncestor(TreeNode *r, TreeNode *p, TreeNode *q)
{
    if (!r)
        return NULL;
    if (r == p || r == q)
        return r;
    TreeNode *lt = lowestCommonAncestor(r->left, p, q);
    TreeNode *rt = lowestCommonAncestor(r->right, p, q);
    if (lt && rt)
        return r;
    if (lt)
        return lt;
    else
        return rt;
}
// 3rd effective way((55%))
class Solution
{
public:
    TreeNode *LCA(TreeNode *r, int r1, int r2)
    {
        if (!r)
            return NULL;
        if (r->val == r1 || r->val == r2)
            return r;
        TreeNode *lt = LCA(r->left, r1, r2);
        TreeNode *rt = LCA(r->right, r1, r2);
        if (lt && rt)
            return r;
        if (lt)
            return lt;
        else
            return rt;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;
        return LCA(root, p->val, q->val);
    }
};
