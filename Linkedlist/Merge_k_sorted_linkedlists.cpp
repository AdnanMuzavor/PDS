/*
23. Merge k Sorted Lists
Hard

10498

426

Add to List

Share
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
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
// BEST SOLUTION
class Solution
{
public:
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        ListNode *reshead = NULL, *res = NULL;
        if (h1 == NULL && h2)
            return h2;
        if (h2 == NULL && h1)
            return h1;
        if (!h1 && !h2)
            return reshead;
        if (h1->val <= h2->val)
        {
            reshead = h1;
            reshead->next = merge(h1->next, h2);
        }
        else
        {
            reshead = h2;
            reshead->next = merge(h1, h2->next);
        }

        return reshead;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        int l = 0;
        int h = lists.size() - 1;
        while (l < h)
        {
            if (h <= 0)
                break;
            // combine list at low and high and store at low
            // On first iteration lists array will be reduced to half
            // And go on halving at each traversal
            lists[l] = merge(lists[l], lists[h]);
            l++;
            h--;
            // If l becoems greater thn high means even lists combined
            // Since l is one step ahead of high
            // we shidt l=0 and high to l-1

            if (l > h)
            {
                h = l - 1;
                l = 0;
            }
            // If l==h means new high is the same point i.e curr high
            // and low to be shifted to 0
            else if (l == h)
            {
                h = l;
                l = 0;
            }
        }

        return lists[l];
    }
};
// BRUTE FORCE
class Solution
{
public:
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        ListNode *reshead = NULL, *res = NULL;
        if (h1 == NULL && h2)
            return h2;
        if (h2 == NULL && h1)
            return h1;
        if (!h1 && !h2)
            return reshead;
        if (h1->val <= h2->val)
        {
            reshead = res = h1;
            h1 = h1->next;
        }
        else
        {
            reshead = res = h2;
            h2 = h2->next;
        }
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                res->next = h1;
                h1 = h1->next;
                res = res->next;
            }
            else
            {
                res->next = h2;
                h2 = h2->next;
                res = res->next;
            }
        }
        while (h1)
        {
            res->next = h1;
            h1 = h1->next;
            res = res->next;
        }
        while (h2)
        {
            res->next = h2;
            h2 = h2->next;
            res = res->next;
        }
        res->next = NULL;
        return reshead;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        int l = 0;
        int h = lists.size() - 1;
        // Brute force: Combine each list with list[0]
        // And decrement pointer high pointer
        // Return list[0]
        while (l < h)
        {
            if (h == 0)
                break;
            lists[0] = merge(lists[0], lists[h]);

            h--;
        }

        return lists[0];
    }
};
// BETTER THN BRUTE FORCE
// COMBINE 2 LISTS AT A TIME AND SHIFT L=0
// WHENVER H AND L CROSS PASS
// AND UPDATE HIGH TO COMBINED LIST

class Solution
{
public:
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        ListNode *reshead = NULL, *res = NULL;
        if (h1 == NULL && h2)
            return h2;
        if (h2 == NULL && h1)
            return h1;
        if (!h1 && !h2)
            return reshead;
        if (h1->val <= h2->val)
        {
            reshead = res = h1;
            h1 = h1->next;
        }
        else
        {
            reshead = res = h2;
            h2 = h2->next;
        }
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                res->next = h1;
                h1 = h1->next;
                res = res->next;
            }
            else
            {
                res->next = h2;
                h2 = h2->next;
                res = res->next;
            }
        }
        while (h1)
        {
            res->next = h1;
            h1 = h1->next;
            res = res->next;
        }
        while (h2)
        {
            res->next = h2;
            h2 = h2->next;
            res = res->next;
        }
        res->next = NULL;
        return reshead;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        int l = 0;
        int h = lists.size() - 1;
        while (l < h)
        {
            if (h <= 0)
                break;
            // combine list at low and high and store at low
            // On first iteration lists array will be reduced to half
            // And go on halving at each traversal
            lists[l] = merge(lists[l], lists[h]);
            l++;
            h--;
            // If l becoems greater thn high means even lists combined
            // Since l is one step ahead of high
            // we shidt l=0 and high to l-1

            if (l > h)
            {
                h = l - 1;
                l = 0;
            }
            // If l==h means new high is the same point i.e curr high
            // and low to be shifted to 0
            else if (l == h)
            {
                h = l;
                l = 0;
            }
        }

        return lists[l];
    }
};