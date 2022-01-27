/*
114. Flatten Binary Tree to Linked List
Medium

6329

447

Add to List

Share
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.


Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
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
//HIGHLY OPTIMISED
    void flatten(TreeNode *root) {
	while (root) {
		if (root->left && root->right) {
			TreeNode* t = root->left;
			while (t->right)
				t = t->right;
			t->right = root->right;
		}

        if(root->left)
		    root->right = root->left;
		root->left = NULL;
		root = root->right;
	}
//BRUTE FORCE BUT EFFICIENT
class Solution {
public:
    vector<TreeNode*> op;
    void pre(TreeNode*r){
        if(r){
            op.push_back(r);
            pre(r->left);
            pre(r->right);
        }
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        pre(root);
        root=op[0];
        root->left=NULL;
        TreeNode*p=root;
        for(int i=1;i<op.size();i++){
            p->left=NULL;
            p->right=op[i];
            p=p->right;
        }
        p->right=NULL;
    }
};