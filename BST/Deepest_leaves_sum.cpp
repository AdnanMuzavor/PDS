/*
1302. Deepest Leaves Sum
Medium

2152

70

Add to List

Share
Given the root of a binary tree, return the sum of values of its deepest leaves.


Example 1:


Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19

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

// METHOD-I
class Solution
{
public:
    int sum = 0;
    int ht(TreeNode *r)
    {
        if (r)
        {
            int lh = ht(r->left);
            int rh = ht(r->right);
            return max(lh, rh) + 1;
        }
        return 0;
    }
    void maxsum(TreeNode *r, int h)
    {
        h--;
        if (r && h == 0)
        {
            sum += r->val;
            return;
        }
        else if (r)
        {
            maxsum(r->left, h);
            maxsum(r->right, h);
        }
        else
        {
            return;
        }
    }
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val;
        int h = ht(root);
        maxsum(root, h);
        return sum;
    }
};

// METHOD-II- level order traversal

     int deepestLeavesSum(TreeNode* root) {
        int res = 0, i;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            //Doing a typical level-order traversal
            
            //for-loop
           // for (i = q.size() - 1, res = 0; i >= 0; --i) 
            int sz=q.size();
            res=0;
            //while-loop
            while(sz--)
            {
                
                
                //res i.e result will be rein itialise at every level
                TreeNode* node = q.front(); q.pop();
                //At last level res will have sum of nodes at this level
                res += node->val;
                if (node->right) q.push(node->right);
                if (node->left)  q.push(node->left);
            }
        }
         //res val at last level will be returned
        return res;
    }