/*
2095. Delete the Middle Node of a Linked List
Medium

437

16

Add to List

Share
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.


Example 1:


Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.
Example 2:


Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.
Example 3:


Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.
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
        ListNode *p = h;
        int l = 0;
        while (p != NULL)
        {
            l++;
            p = p->next;
        }
        return l;
    }
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head || !head->next)
            return NULL;
        int mid = length(head) / 2;
        ListNode *p = head, *q = NULL;
        while (mid--)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        return head;
    }
};

//optimised
ListNode* deleteMiddle(ListNode* head) {
	  // edge case conditions
       if (head == NULL) {
          return NULL;
       }
       if (head->next == NULL) {
          delete head;
          return NULL;
       }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head; // keeping this prev node to get the previous node of slow pointer when we reach middle
        while(fast != NULL && fast->next != NULL)
        {
            if(slow != head) prev = prev->next; // since we want prev to start one step later than slow node
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }