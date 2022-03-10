/*
173. Binary Search Tree Iterator
Medium

4933

358

Add to List

Share
Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.



Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
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

class BSTIterator
{
public:
    vector<int> inorder;
    int index = 0;
    void in(TreeNode *r)
    {
        if (r)
        {
            in(r->left);
            inorder.push_back(r->val);
            in(r->right);
        }
    }
    BSTIterator(TreeNode *root)
    {
        TreeNode *dummy = new TreeNode(-1);
        dummy->left = root;
        in(dummy);
        cout << "Inorder traversal  is: ";
        for (auto e : inorder)
            cout << e << " ";
        cout << endl;
    }

    int next()
    {
        if (index <= inorder.size() - 2)
        {
            int ans = inorder[index];
            index++;
            return ans;
        }
        return -1;
    }

    bool hasNext()
    {
        if (index >= inorder.size() - 1 || inorder[index] == -1)
            return false;
        return true;
    }
};