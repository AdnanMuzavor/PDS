/*
230. Kth Smallest Element in a BST
Medium

5754

113

Add to List

Share
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.



Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
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
    vector<int> op;
    void inorder(TreeNode *t)
    {
        if (t)
        {
            inorder(t->left);
            op.push_back(t->val);
            inorder(t->right);
        }
    }
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        // for(auto e:op){
        //     cout<<e<<endl;
        // }
        if (k <= op.size())
        {
            return op[k - 1];
        }
        return -1;
    }
};