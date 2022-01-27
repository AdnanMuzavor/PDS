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
public:
    // initialise with '~' because '~' has maximum value
    string sol = "~";
    void recur(TreeNode *r, string s)
    {
        if (!r)
            return;
        if (!r->left && !r->right)
        {
            sol = min(sol, char(r->val + 'a') + s);
        }
        // r->val+'a' will give value startimg from
        // 97 when r->val=0
        // 98 when r->val=1
        // and so on
        // further
        // char(97)-> 'a'
        // char(98)-> 'b'
        // and so on
        // this will be appended to string before further processing
        recur(r->left, char(r->val + 'a') + s);
        recur(r->right, char(r->val + 'a') + s);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        recur(root, "");
        return sol;
    }
};