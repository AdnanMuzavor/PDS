/*
606. Construct String from Binary Tree
Easy

1248

1624

Add to List

Share
Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

 

Example 1:


Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
Example 2:


Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.
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

class Solution {
public:
    TreeNode*t=NULL;
    string tostr(TreeNode*root,string s1){
        if(!root && s1=="left") return "()";
        if(!root && s1=="right") return "";
        string s="";
        if(!root->left && !root->right){
            s+="(";
            s+=to_string(root->val);
            s+=")";
            return s;
        }
        if(t!=root)s+="(";
        s+=to_string(root->val);
        s+=tostr(root->left,"left");
        s+=tostr(root->right,"right");
        if(t!=root)s+=")";
        return s;
    }
    string tree2str(TreeNode* root) {
        if(!root) return "";
        if(!root->left && !root->right) return to_string(root->val);
        t=root;
        return tostr(root,"");
    }
};