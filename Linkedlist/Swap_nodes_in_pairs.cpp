/*
24. Swap Nodes in Pairs
Medium

5534

268

Add to List

Share
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)



Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *nxt = NULL;
        ListNode *prev = NULL;
        if (!head)
            return NULL;
        int k = 2;
        // Reverse 2 nodes(same as swapping them)
        while (curr && k)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            k--;
        }
        // after reversing ehad will be last node in range 2
        // so connecting head 0> next with next swapped pair
        // which starts from curr node hence passing current
        head->next = swapPairs(curr);

        // return prev because it's the new head
        return prev;
    }
};
