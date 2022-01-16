/*
19. Remove Nth Node From End of List
Medium

8323

405

Add to List

Share
Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
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

class Solution
{
public:
    ListNode *length(ListNode *r, int k, int &d)
    {
        ListNode *p = r;
        int l = 0;
        while (p != NULL)
        {
            p = p->next;
            l++;
        }
        if (l == k && k == 1)
        {
            d = -1;
        }
        if (k > l)
        {
            d = -2;
        }
        //  cout<<l<<endl;
        p = r;
        int req = l - k;
        while (req--)
        {
            p = p->next;
        }
        d = p->val;
        cout << p->val << endl;
        return p;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int d = 0;
        ListNode *node = length(head, n, d);
        if (d == -1)
            return NULL;
        if (d == -2)
            return head;
        if (head == node)
        {
            head = head->next;
            return head;
        }
        ListNode *p = head;

        while (p->next != node)
        {
            p = p->next;
        }

        p->next = p->next ? p->next->next : NULL;

        return head;
    }
};
