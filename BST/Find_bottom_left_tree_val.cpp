/*
513. Find Bottom Left Tree Value
Medium

1911

202

Add to List

Share
Given the root of a binary tree, return the leftmost value in the last row of the tree.



Example 1:


Input: root = [2,1,3]
Output: 1
Example 2:


Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
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
    int lf = 0;
    int maxht = 0;
    void findleft(TreeNode *r, int h, bool left)
    {
        if (!r)
            return;
        // If it's left node and we are at max-level
        if (!r->left && !r->right && h >= maxht && left)
            lf = r->val;
        // If it's right node and we are on last-level
        else if (!r->left && !r->right && h >= maxht && !left)
            lf = r->val;
        // updating maxheight before going to next levels
        maxht = max(maxht, h);
        findleft(r->right, h + 1, false);
        findleft(r->left, h + 1, true);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val;
        findleft(root, 0, false);
        return lf;
    }
};