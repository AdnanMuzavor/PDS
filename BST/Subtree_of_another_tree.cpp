/*
572. Subtree of Another Tree
Easy

4695

233

Add to List

Share
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.



Example 1:


Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true
Example 2:


Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
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
// Approach 1 :Recursion
class Solution
{
public:
    bool sametree(TreeNode *r1, TreeNode *r2)
    {
        // Both are NULL
        if (!r1 && !r2)
            return true;
        // One of them is NULL
        if (!r1 || !r2)
            return false;
        // Both exist and have equal values
        if (r1 && r2 && r1->val == r2->val)
        {
            bool a = sametree(r1->left, r2->left);   // Checking left subtrees
            bool b = sametree(r1->right, r2->right); // checking right subtrees
            //  If left and right subtree both matches

            if (a && b)
                return true;
        }
        return false;
    }
    bool isSubtree(TreeNode *root, TreeNode *subroot)
    {
        if (root && !subroot)
            return true;
        if (!root && subroot)
            return false;
        // Checking if root and subroot both are same trees
        if (sametree(root, subroot))
        {
            return true;
        }

        // Else checking root's left and root'right
        bool a = isSubtree(root->left, subroot);
        // If left subtree gives wrequired ans no need to check next
        if (a)
            return true;
        bool b = isSubtree(root->right, subroot);
        // If any one of the two is true means subtree is found
        // hence return true
        if (a || b)
            return true;
        return false;
    }
};

//  Approach 2: mapping strings
class Solution
{
public:
    unordered_map<string, int> m;
    string comp(TreeNode *r, string c, string type)
    {
        if (!r && type == "l")
            return "($)";
        if (!r && type == "r")
            return "(&)";
        string s = "";
        if (!r->left && !r->right)
        {
            s += "(";
            s += to_string(r->val);
            s += ")";
            if (c != "sub")
                m[s] = 10;
            return s;
        }
        s += "(";
        s += to_string(r->val);
        s += comp(r->left, c, "l");
        s += comp(r->right, c, "r");
        s += ")";
        if (c != "sub")
            m[s] = 10;
        // cout<<s<<endl;
        return s;
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        comp(root, "", "");
        string sol = comp(subRoot, "sub", "");
        if (m[sol] >= 1)
        {
            return true;
        }
        return false;
    }
};
