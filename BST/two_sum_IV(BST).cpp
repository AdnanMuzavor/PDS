/*
653. Two Sum IV - Input is a BST
Easy

3169

190

Add to List

Share
Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.



Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
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
    // Map fro keeping track of each element and times it occurs
    // Eg if k=6 and v[i]=3 thn 6-3=3 means there should be 2
    // 3s i.e m[3]=2
    unordered_map<int, int> m;
    vector<int> v;
    void pre(TreeNode *t)
    {
        if (t)
        {
            m[t->val]++;
            v.push_back(t->val);
            pre(t->left);
            pre(t->right);
        }
    }
    bool findTarget(TreeNode *root, int k)
    {
        if (!root || (!root->left && !root->right))
            return false;
        pre(root);
        for (auto e : v)
        {
            int m1 = k - e;
            // if k=6,e=3 means 6-3=3 means m[3]=2
            if (m1 == e && m[e] >= 2)
                return true;
            // if m1!=k means elements are unique so one copy or any number of copies of m1 are
            // accepted
            if (m1 != e && m[m1])
                return true;
        }
        return false;
    }
};
