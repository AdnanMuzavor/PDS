/*
515. Find Largest Value in Each Tree Row
Medium

1819

79

Add to List

Share
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
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
//OPTIMISED SOLUTION
class Solution {
public:
    vector<int> op;
    void helper(TreeNode*r,int row){
        if(!r) return;
       
        //Indicates that element from this row was not yet compared
        if(op.size()<=row){
            op.push_back(r->val);
        }
        //Indicates that element from this row was added and now we 
        //found another element in same row hence we compre and
        //kepe the maximum one into the array
        else{
            op[row]=max(op[row],r->val);
        }
        //Finding left half wihich is at next level hence row+1
        helper(r->left,row+1);
        helper(r->right,row+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return op;
        helper(root,0);
        return op;
    }
};


//BRUTE FORCE
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> op;
        if (!root)
            return op;
        if (!root->left && !root->right)
        {
            op.push_back(root->val);
            return op;
        }
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int sz = q.size();
            int maxi = INT_MIN;
            while (sz--)
            {
                TreeNode *t = q.front();
                q.pop();
                maxi = max(maxi, t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
            op.push_back(maxi);
            maxi = INT_MIN;
        }
        return op;
    }
};