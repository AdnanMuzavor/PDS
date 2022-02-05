/*
1721. Swapping Nodes in a Linked List
Medium

1435

69

Add to List

Share
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
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
            p = p->next;
            l++;
        }
        return l;
    }
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *p = head;
        ListNode *q = head;
        // Getting length
        int l = length(head);
        if (l == 1)
            return head;
        int back = l - k;
        k = k - 1;
        // Getting to kth node from first
        while (k)
        {
            p = p->next;
            k--;
        }
        cout << p->val << endl;
        // storing val of kth node from beginning
        int backval = p->val;

        // Getting kth node from last node
        while (back--)
        {
            q = q->next;
        }
        cout << q->val << endl;
        // swapping values
        p->val = q->val;
        q->val = backval;
        return head;
    }
};