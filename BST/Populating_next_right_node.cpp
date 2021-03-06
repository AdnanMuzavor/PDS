/*
116. Populating Next Right Pointers in Each Node
Medium

5594

215

Add to List

Share
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
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
    Node *connect(Node *root)
    {
        Node *d = root;
        while (d != NULL && d->left != NULL)
        {
            Node *t = d;
            while (true)
            {
                t->left->next = t->right;
                if (t->next == NULL)
                    break;
                t->right->next = t->next->left;
                t = t->next;
            }
            d = d->left;
        }
        return root;
    }
};
// brute force
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//        queue<Node*> q;
//        queue<Node*>q2;
//         if(!root){
//             return NULL;
//         }
//         root->next=NULL;
//         if(!root->left && !root->right){
//             return root;
//         }
//         if(root->left){
//             q.push(root->left);

//         }
//         if(root->right){
//             q.push(root->right);
//         }
//         Node *t=new Node(-1);
//         while(!q.empty()){
//            t=q.front();
//            //cout<<t->val<<endl;
//            q.pop();
//           //  cout<<q.front()->val<<endl;
//             int sz=q.size();
//             while(t!=NULL){
//                 if(q.front()){
//                      Node* p1=q.front();
//                      // p1->next=NULL;
//                     t->next=q.front();

//                 }
//                 else{
//                     t->next=NULL;
//                 }
//                 q.pop();
//                 if(t->left)q2.push(t->left);
//                 if(t->right) q2.push(t->right);
//                 if(t->next){
//                       t=t->next;
//                 }
//                 else{
//                     t=t->next;
//                 }

//             }

//             while(!q2.empty()){
//                 t=q2.front();
//                 q2.pop();
//                  if(t->left)q.push(t->left);
//                 if(t->right) q.push(t->right);
//             }

//         }
//         return root;
//     }
// };