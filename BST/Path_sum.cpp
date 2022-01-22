/*
112. Path Sum
Easy

4728

742

Add to List

Share
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
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
    bool currsum(TreeNode*r,int c,int t){
        if(!r) return false;
        //Value matched and node is leaf node thn return true
        if(r->val+c==t && !r->left && !r->right) return true;
        
        //response from right nd left
        bool a=currsum(r->left,r->val+c,t);
        bool b=currsum(r->right,r->val+c,t);
        
        //Either sum at right or left
        if((a==true|| b==true) ) return true;
        
        //if not return false
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        //root itself is leaf and val==target
        if(!root->left && !root->right && root->val==targetSum) return true;
     
        
        //a->left response
        //b->right response
        //a==true or b==true return true
        //return false
        return currsum(root,0,targetSum);
    }
};
