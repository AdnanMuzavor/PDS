/*
113. Path Sum II
Medium

4188

99

Add to List

Share
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.



Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
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
// OPTIMISED APPROACH
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;
    }

private:
    void findPaths(TreeNode *node, int sum, vector<int> &path, vector<vector<int>> &paths)
    {
        if (!node)
            return;
        path.push_back(node->val);
        if (!(node->left) && !(node->right) && sum == node->val)
            paths.push_back(path);
        findPaths(node->left, sum - node->val, path, paths);
        findPaths(node->right, sum - node->val, path, paths);
        path.pop_back();
    }
};

// BRUTE FORCE
class Solution
{
public:
    int sum = 0;
    vector<int> v;
    vector<vector<int>> op;
    void path(TreeNode *r, int target, vector<int> v, int sum)
    {
        if (!r)
            return;

        sum += r->val;
        v.push_back(r->val);
        if (!r->left && !r->right && sum == target)
        {
            op.push_back(v);
            v.pop_back();
            return;
        }

        path(r->left, target, v, sum);
        path(r->right, target, v, sum);
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> v;
        path(root, targetSum, v, 0);
        return op;
    }
};