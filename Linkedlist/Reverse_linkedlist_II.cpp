/*
92. Reverse Linked List II
Medium

5350

255

Add to List

Share
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.



Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        if (!head || !head->next)
            return head;
        int l = 0;
        stack<ListNode *> s;
        ListNode *p = head;
        ListNode *q = NULL;
        ListNode *r = NULL;
        while (p != NULL)
        {
            l++;
            if (l == left)
            {
                while (l <= right)
                {
                    s.push(p);
                    p = p->next;
                    l++;
                }
                break;
            }
            else
            {
                q = p;
                p = p->next;
            }
        }
        if (p)
        {
            r = p;
            cout << r->val << " " << endl;
        }
        if (q == NULL)
        {
            ListNode *res = s.top();
            p = res;
            s.pop();
            while (!s.empty())
            {
                p->next = s.top();
                s.pop();
                p = p->next;
            }
            p->next = r;

            head = res;
            return head;
        }
        else
        {
            ListNode *res = s.top();
            p = res;
            s.pop();
            while (!s.empty())
            {
                p->next = s.top();
                s.pop();
                p = p->next;
            }
            p->next = r;
            q->next = res;

            return head;
        }
        return NULL;
    }
};
