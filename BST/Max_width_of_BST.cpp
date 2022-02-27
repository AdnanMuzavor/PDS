/*
662. Maximum Width of Binary Tree
Medium

3896

624

Add to List

Share
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.



Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
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
    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, long long int>> q;
        // Making queue to have two thinhs one is node
        // Other is index of that node
        // Such that each level will have node starting from index-1
        // Even if index1 is missing we can use index2 if available
        // And get the width using index2-index1

        q.push({root, 0});
        int ans = -1;
        while (!q.empty())
        {
            // v.clear();
            int sz = q.size();
            int min = q.front().second; // Min index will always be given by first node
            long long int first = -1, last = 0;
            while (sz--)
            {
                TreeNode *t = q.front().first; // Getting node
                // Getting index val to hash for left and right
                long long int indexfornext = q.front().second - min;
                // If first is -1 means it not initialised yet
                if (first == -1)
                    first = indexfornext;
                // Last will be updated and alst node value at this level will be in last
                last = indexfornext;
                q.pop();
                if (t->left)
                {
                    q.push({t->left, (2 * indexfornext) + 1});
                }
                if (t->right)
                {
                    q.push({t->right, (2 * indexfornext) + 2});
                }
            }

            // cout<<" v size: "<<v.size()<<endl;;
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};