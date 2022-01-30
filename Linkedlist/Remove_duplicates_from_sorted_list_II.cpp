/*
82. Remove Duplicates from Sorted List II
Medium

4339

146

Add to List

Share
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
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
// POWERDUL APPROACH
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Making a dummy node
        ListNode *s = new ListNode(0, head);
        // Making prev point to this dummy node
        ListNode *p = s;
        while (head != NULL)
        {
            if (head->next && head->val == head->next->val)
            {
                while (head->next && head->val == head->next->val)
                {
                    head = head->next;
                }
                // Make prev next point to head->next
                p->next = head->next;
            }
            // else move prev to next node
            else
            {
                p = p->next;
            }
            // Leeping moving head ahead
            head = head->next;
        }
        return s->next;
    }
};
// BRUTE FORCE
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        // BRUTE FORCE APPROACH
        map<int, int> m;
        ListNode *p = head;
        while (p != NULL)
        {
            m[p->val]++;
            p = p->next;
        }
        ListNode *res = NULL;
        for (auto e : m)
        {
            if (e.second == 1)
            {
                ListNode *t = new ListNode(e.first);
                if (res == NULL)
                    res = p = t;
                else
                {
                    p->next = t;
                    p = p->next;
                }
            }
        }
        return res;
    }
};
