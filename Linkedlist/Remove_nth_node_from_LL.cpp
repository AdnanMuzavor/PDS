/*
19. Remove Nth Node From End of List
Medium

8323

405

Add to List

Share
Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
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
    ListNode *length(ListNode *r, int k, int &d)
    {
        ListNode *p = r;
        int l = 0;
        while (p != NULL)
        {
            p = p->next;
            l++;
        }
        if (l == k && k == 1)
        {
            d = -1;
        }
        if (k > l)
        {
            d = -2;
        }
        //  cout<<l<<endl;
        p = r;
        int req = l - k;
        while (req--)
        {
            p = p->next;
        }
        d = p->val;
        cout << p->val << endl;
        return p;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int d = 0;
        ListNode *node = length(head, n, d);
        if (d == -1)
            return NULL;
        if (d == -2)
            return head;
        if (head == node)
        {
            head = head->next;
            return head;
        }
        ListNode *p = head;

        while (p->next != node)
        {
            p = p->next;
        }

        p->next = node->next;

        return head;
    }
};
// EFFIECIENT SLN
/*
The difference between the final node and the to_be_delete node is N. And here the assumption is that n is always valid.

fast pointer points to the node which is N step away from the to_be_delete node.

slow pointer points to the to_be_delete node.

The algorithms is described as below:

Firstly, move fast pointer N step forward.

Secondly,move fast and slow pointers simultaneously one step a time forward till the fast pointer reach the end, which will cause the slow pointer points to the previous node of the to_be_delete node.

Finally, slow->next = slow->next->next.
*/
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;

        ListNode new_head(-1);
        new_head.next = head;

        ListNode *slow = &new_head, *fast = &new_head;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *to_be_deleted = slow->next;
        slow->next = slow->next->next;

        delete to_be_deleted;

        return new_head.next;
    }
};
