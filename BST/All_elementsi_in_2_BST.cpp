/*
1305. All Elements in Two Binary Search Trees
Medium

1907

55

Add to List

Share
Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.



Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
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
    void pre(TreeNode *root1, vector<int> &sol)
    {
        if (root1)
        {
            sol.push_back(root1->val);
            pre(root1->left, sol);
            pre(root1->right, sol);
        }
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> sol;
        pre(root1, sol);
        pre(root2, sol);
        sort(sol.begin(), sol.end());
        return sol;
    }
};
