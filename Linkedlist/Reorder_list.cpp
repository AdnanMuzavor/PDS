/*
143. Reorder List
Medium

5168

198

Add to List

Share
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
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
    int length(ListNode *h)
    {
        int l = 0;
        ListNode *p = h;
        while (p)
        {
            l++;
            p = p->next;
        }
        return l;
    }
    void reorderList(ListNode *head)
    {
        vector<ListNode *> op1, op2, op3;
        int l = length(head);
        if (l == 1 || l == 2)
            return;
        int mid = l / 2;
        ListNode *p = head;
        // Getting first half stored in op1
        while (mid--)
        {
            op1.push_back(p);
            p = p->next;
        }
        // Getting second half stored in op2
        while (p)
        {
            op2.push_back(p);
            p = p->next;
        }
        // Reversing the second half
        reverse(op2.begin(), op2.end());

        int i = 0, j = 0;

        // Combining first and second half in manner of required o/p
        while (i < op1.size() && j < op2.size())
        {
            op3.push_back(op1[i++]);
            op3.push_back(op2[j++]);
        }
        // Adding remain ing nodes if any
        while (i < op1.size())
        {
            op3.push_back(op1[i++]);
        }
        while (j < op2.size())
        {
            op3.push_back(op2[j++]);
        }

        // Making linkedlist out of these nodes
        ListNode *res = op3[0];
        p = res;
        for (int i = 1; i < op3.size(); i++)
        {
            p->next = op3[i];
            p = p->next;
        }
        p->next = NULL;
        head = res;
    }
};
