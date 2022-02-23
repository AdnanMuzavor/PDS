/*
103. Binary Tree Zigzag Level Order Traversal
Medium

5307

166

Add to List

Share
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
*/
#include <bits/stdc++.h>
using namespace std;

// O(n+log(k)) Time (n is number of nodes)
// logk is time to reverse array of k nodes
// Definition for a Node.
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;

    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val, TreeNode *_left, TreeNode *_right, TreeNode *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<int> temp1;
        vector<vector<int>> op;
        if (!root)
            return op;
        queue<TreeNode *> q;
        q.push(root);
        int i = 1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                TreeNode *t = q.front();
                q.pop();
                temp1.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            if (i % 2 == 0)
                reverse(temp1.begin(), temp1.end());
            op.push_back(temp1);
            temp1.clear();
            i++;
        }
        return op;
    }
};