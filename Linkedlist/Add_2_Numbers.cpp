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
        ListNode *p = NULL;
        ListNode *res = NULL;
        int s = 0, c = 0;
        while (l1 != NULL || l2 != NULL)
        {
            s = c + s + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            c = s >= 10 ? 1 : 0;
            s = s >= 10 ? s % 10 : s;
            ListNode *tmp = new ListNode(s);
            if (res == NULL)
            {
                p = res = tmp;
            }
            else
            {
                p->next = tmp;
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
            ListNode *tmp = new ListNode(c);
            p->next = tmp;
        }
        return res;
    }
};