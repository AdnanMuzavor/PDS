/*
445. Add Two Numbers II
Medium

3094

223

Add to List

Share
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
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
    ListNode *reverse(ListNode *root)
    {
        ListNode *prev = NULL;
        ListNode *next = NULL;
        ListNode *curr = root;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        root = prev;
        return root;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode *res = NULL;
        ListNode *p = NULL;
        int s = 0, c = 0;
        while (l1 != NULL || l2 != NULL)
        {
            s = c + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            c = s >= 10 ? 1 : 0;
            s = s >= 10 ? s % 10 : s;
            ListNode *t = new ListNode(s);
            if (res == NULL)
            {
                p = res = t;
            }
            else
            {
                p->next = t;
                p = p->next;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
            s = 0;
        }
        if (c != 0)
        {
            ListNode *t = new ListNode(c);
            p->next = t;
        }

        return reverse(res);
    }
};