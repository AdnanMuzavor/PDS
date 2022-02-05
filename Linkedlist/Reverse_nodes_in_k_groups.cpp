/*
25. Reverse Nodes in k-Group
Hard

6184

469

Add to List

Share
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *curr = head, *prev = NULL, *next = NULL;
        // If length of remaining list is less thn k
        // return head without reversing
        if (length(head) < k)
            return head;
        int i = k;
        while (curr && i)
        {

            cout << "At node: " << curr->val << endl;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i--;
        }
        // head evertime will be pointing to node which is last node of
        // new reversed linkedlist, hence we set head->next to remaining group
        // where curr node in next list which will be our head for reversing next linkedlist
        if (next != NULL)
        {

            head->next = reverseKGroup(curr, k);
        }
        return prev;
    }
};