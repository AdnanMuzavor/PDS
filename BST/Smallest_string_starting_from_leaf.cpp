/*
988. Smallest String Starting From Leaf
Medium

963

163

Add to List

Share
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.



Example 1:


Input: root = [0,1,2,3,4,3,4]
Output: "dba"
Example 2:


Input: root = [25,1,3,1,3,0,2]
Output: "adz"
*/
#include <bits/stdc++.h>
using namespace std;

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
    string answer = "~";

public:
    void recure(TreeNode *root, string s)
    {
        if (!root)
            return;
        if (!root->left && !root->right)
        {
            answer = min(answer, char(root->val + 'a') + s);
        }
        recure(root->left, char(root->val + 'a') + s);
        recure(root->right, char(root->val + 'a') + s);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        recure(root, "");
        return answer;
    }
};
