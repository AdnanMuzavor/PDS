/*
1302. Deepest Leaves Sum
Medium

2152

70

Add to List

Share
Given the root of a binary tree, return the sum of values of its deepest leaves.


Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

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
    int sum = 0;
    int ht(TreeNode *r)
    {
        if (r)
        {
            int lh = ht(r->left);
            int rh = ht(r->right);
            return max(lh, rh) + 1;
        }
        return 0;
    }
    void maxsum(TreeNode *r, int h)
    {
        h--;
        if (r && h == 0)
        {
            sum += r->val;
            return;
        }
        else if (r)
        {
            maxsum(r->left, h);
            maxsum(r->right, h);
        }
        else
        {
            return;
        }
    }
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val;
        int h = ht(root);
        maxsum(root, h);
        return sum;
    }
};