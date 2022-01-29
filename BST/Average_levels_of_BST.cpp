/*
637. Average of Levels in Binary Tree
Easy

2684

223

Add to List

Share
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.


Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].
Example 2:


Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]
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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> op;
        if (!root->left && !root->right)
        {
            op.push_back(root->val / (double)1);
            return op;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            long long int sum = 0, c = 0;
            long long int sz = q.size();
            while (sz--)
            {
                TreeNode *t = q.front();
                q.pop();
                sum += t->val;
                c++;
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            op.push_back(sum / (double)c);
        }
        return op;
    }
};