/*
148. Sort List
Medium

6189

209

Add to List

Share
Given the head of a linked list, return the list after sorting it in ascending order.



Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []

*/

#include <bits/stdc++.h>
using namespace std;

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
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    // BRUTE FORCE
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *res = new ListNode(head->val);
        res->next = NULL;
        ListNode *q = NULL, *r = NULL;
        ListNode *p = head->next;

        while (p)
        {
            ListNode *t = new ListNode(p->val);
            //  cout<<p->val<<endl;
            if (p->val <= res->val)
            {

                t->next = res;
                res = t;
            }
            else
            {
                r = NULL;
                q = res;

                while (q && q->val < t->val)
                {
                    r = q;
                    q = q->next;
                }
                r->next = t;
                t->next = q;
            }
            p = p->next;
        }
        return res;
    }
    // OPtimised
    ListNode *merge(ListNode *a, ListNode *b)
    {
        if (!a && !b)
            return NULL;
        if (!a)
            return b;
        if (!b)
            return a;
        ListNode *res = NULL;
        if (a->val <= b->val)
        {
            res = a;
            res->next = merge(a->next, b);
        }
        else
        {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        vector<ListNode *> op;
        ListNode *p = head, *q = NULL;
        while (p)
        {
            q = p;
            p = p->next;
            q->next = NULL;
            op.push_back(q);
        }
        int l = 0, h = op.size() - 1;
        while (l < h)
        {
            if (h == 0)
                break;
            op[l] = merge(op[l], op[h]);
            l++;
            h--;
            if (l > h)
            {
                h = l - 1;
                l = 0;
            }
            if (l == h)
            {
                h = l;
                l = 0;
            }
        }
        return op[0];
    }
};

// O(NLOGN)merge sort and O(1) space
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
    ListNode *merge(ListNode *a, ListNode *b)
    {
        if (!a && !b)
            return NULL;
        if (!a)
            return b;
        if (!b)
            return a;
        ListNode *res = NULL;
        if (a->val <= b->val)
        {
            res = a;
            res->next = merge(a->next, b);
        }
        else
        {
            res = b;
            res->next = merge(a, b->next);
        }
        return res;
    }
    ListNode *getmid(ListNode *h)
    {
        ListNode *f = h, *s = h;
        while (f && f->next && f->next->next)
        {
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *mid = getmid(head);
        ListNode *left = head;    // Left node
        ListNode *rt = mid->next; // ryt node
        mid->next = NULL;

        // Split the the current lists
        left = sortList(left);
        rt = sortList(rt);

        // return NULL;
        // Merge them and return
        return merge(left, rt);
    }
};