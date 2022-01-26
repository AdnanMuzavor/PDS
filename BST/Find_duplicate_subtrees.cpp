/*
652. Find Duplicate Subtrees
Medium

2850

280

Add to List

Share
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.



Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
Example 3:


Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
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
    unordered_map<string, int> m;

    string dup(TreeNode *root, vector<TreeNode *> &v)
    {
        // If root does'nt exist
        if (!root)
            return "";

        // To distinguish between similar nos
        string s = "(";

        // If root ->left and root->right does'nt exist finish work here only
        if (!root->left && !root->right)
        {
            s += to_string(root->val);
            s += ")";
            // if m[s] exist and != -100 means it's duplicate and not
            // previously added in output array so adding it and making m[s]=-100
            // which indicates that node is visited
            if (m[s] && m[s] != -100)
            {
                v.push_back(root);

                m[s] = -100;
            }
            // Means node was'nt added into output and is encountered first time
            // as here m[s] will be ==0 which is !=-100 hence enters in if block
            else if (m[s] != -100)
            {
                m[s]++;
            }
            return s;
        }
        // When root left exist visit left side thn root thn right side
        s += dup(root->left, v);
        s += to_string(root->val);
        s += dup(root->right, v);
        s += ")";

        // if m[s] exist and != -100 means it's duplicate and not
        // previously added in output array so adding it and making m[s]=-100
        // which indicates that node is visited
        if (m[s] && m[s] != -100)
        {

            v.push_back(root);

            m[s] = -100;
        }
        // Means node was'nt added into output and is encountered first time
        // as here m[s] will be ==0 which is !=-100 hence enters in if block
        else if (m[s] != -100)
        {

            m[s]++;
        }
        return s;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        // To keep track of output
        vector<TreeNode *> v;
        // If no left and right means no duplivcatw trees
        if (!root->left && !root->right)
            return v;
        // Sending to a function
        dup(root, v);
        return v;
    }
};