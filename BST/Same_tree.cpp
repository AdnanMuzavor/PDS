/*
100. Same Tree
Easy

4901

117

Add to List

Share
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    bool isSameTree(Node *p, Node *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p && q && p->val == q->val)
        {
            bool a = isSameTree(p->left, q->left);
            bool b = isSameTree(p->right, q->right);
            return a && b;
        }
        return false;
    }
};
