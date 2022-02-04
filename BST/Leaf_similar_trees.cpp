/*
872. Leaf-Similar Trees
Easy

1554

54

Add to List

Share
Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



Example 1:


Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
Output: true
Example 2:


Input: root1 = [1,2,3], root2 = [1,3,2]
Output: false
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
// Efficient soln-1
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    string t1, t2;
    DFS(root1, t1);
    DFS(root2, t2);
    return t1 == t2;
}

void DFS(TreeNode *root, string &s)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        s += to_string(root->val) + "#";
    DFS(root->left, s);
    DFS(root->right, s);
}

;
// Efficient soln-2
class Solution
{
public:
    vector<int> v1;
    bool ans = true;
    int c = 0;
    void leaf(TreeNode *h, bool v)
    {
        if (!h)
            return;
        // If v true means push into the array
        if (!h->left && !h->right && v)
            v1.push_back(h->val);
        // if v false means check if current leaf->val==vector[curr-position] val
        // if so increment curr-position so that next time for next leaf ,next value in order
        // in vector is checked
        // if value dont match make ans=0
        if (!h->left && !h->right && !v)
        {
            if (v1[c] == h->val)
            {
                c++;
            }
            else
            {
                ans = false;
            }
        }
        // If not leaf bnode go ahead with left and right nodes
        leaf(h->left, v);
        leaf(h->right, v);
    }
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        // true for root1 to form a vector
        // false for root2 so as to check values
        leaf(root1, true);
        leaf(root2, false);
        return ans && c == v1.size();
    }
};