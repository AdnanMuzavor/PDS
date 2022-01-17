/*
203. Remove Linked List Elements
Easy

4270

153

Add to List

Share
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.



Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // Empty list case
        if (head == NULL)
            return head;

        // First N nodes/All nodes with val to be deleted
        while (head && head->val == val)
        {
            head = head->next;
        }
        if (head == NULL)
            return head;
        ListNode *p = head;

        // Deleting nodes with val given
        while (p != NULL && p->next != NULL)
        {
            if (p->next->val == val)
            {
                //.push(p->next);
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        cout << p->val << endl;
        // If one node is left and that too has val given thn deleted
        if (p->val == val)
        {
            p = p->next;
            return p;
        }
        return head;
    }
};