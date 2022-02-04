/*
199. Binary Tree Right Side View
Medium

5793

318

Add to List

Share
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.



Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> op;
        if (!root)
            return op;

        queue<TreeNode *> q;
        q.push(root);
        TreeNode *t = NULL;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                // For last iteration t will have left most node-value
                // at that level
                // So after this while loop breaks we add t->value into output array
                t = q.front();
                q.pop();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            op.push_back(t->val);
        }
        return op;
    }
};