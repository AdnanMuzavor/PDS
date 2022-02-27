/*
138. Copy List with Random Pointer
Medium

7360

927

Add to List

Share
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.



Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node
{
    int val;
    Node *next;
    Node *random;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

// Not suitable for duplicate nodes
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Map node value with val of to which random poin ter points
        unordered_map<int, int> m;
        // Map nodes with thier values
        unordered_map<int, Node *> m2;
        Node *h1 = head;
        while (h1)
        {
            m[h1->val] = h1->random ? h1->random->val : -1;
            h1 = h1->next;
        }
        for (auto e : m)
        {
            cout << e.first << " random point to " << e.second << endl;
        }
        // Creating a copy of LL and merging new nodes with their values
        Node *res = new Node(head->val);

        Node *curr = res;
        m2[head->val] = curr;
        Node *h = head->next;
        while (h)
        {
            //  nodes.push_back(curr);
            Node *newnode = new Node(h->val);
            m2[newnode->val] = newnode;
            curr->next = newnode;
            curr = curr->next;
            h = h->next;
        }

        for (auto e : m)
        {
            // Connecting new LL's value eith corresponding random nodes with help of values
            if (e.second != -1)
            {
                cout << e.first << " ->random = " << e.second << endl;
                cout << m2[e.first]->val << " ->random " << m2[e.second]->val << endl;
                m2[e.first]->random = m2[e.second];
            }
        }
        return res;
    }
};

// Proper appraoch but with extra space
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // map to correspond to copy of origin al node
        unordered_map<Node *, Node *> m;
        Node *h = head;
        // Dummy and runner will help in pointing next pointers in clone LL
        Node *dummy = new Node(-10);
        Node *runner = dummy;
        while (h)
        {
            Node *newcopy = new Node(h->val);
            // Linking next pointers of clone LL
            runner->next = newcopy;
            // Moving runner ahead to point next NULLL pointers
            runner = runner->next;
            m[h] = newcopy; // Mapping original node with it's copy
            h = h->next;
        }
        // Setting h back to head, and runner to head of clone LL
        h = head;
        runner = dummy->next;
        while (h)
        {
            // If curr node has random
            // Thedn we can get clone of random node it's pointing to m[h->random]
            if (h->random != NULL)
            {
                // Hence we link random pointers
                runner->random = m[h->random];
            }
            // We move both pointers ahead simultaneously
            runner = runner->next;
            h = h->next;
        }
        return dummy->next;
    }
};

// OPtimised O(N) time and O(1) space

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Linking copy nodes to next  of original nodes
        Node *newNode = NULL;
        Node *curr = head;
        // PartI, Linking original nodes with teir copies
        while (curr)
        {
            newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = curr->next->next;
        }
        // PartII, Linking random pointers of copyNodes
        curr = head;
        while (curr)
        {
            // curr->next->random means copy-node->random
            // curr->random->next means copy of random node
            if (curr && curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // Making reshead point to head of copy LL
        Node *reshead = new Node(0);
        curr = head;              // head of original linkedlist
        Node *copycurr = reshead; // head of copy linkedlist
        // PartIII, Separating LLs

        while (curr)
        {
            // Storing next of copycurr
            Node *node = curr->next->next;
            // Extract copy node
            copycurr->next = curr->next;
            // Moving it to next node in copy LL
            copycurr = copycurr->next;
            // Restoring old LL next pointer
            curr->next = node;
            // Making curr to next node in original LL and repeat
            curr = curr->next;
        }
        return reshead->next;
    }
};