/*
328. Odd Even Linked List
Medium

4969

380

Add to List

Share
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.



Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;
        // odd,oddhead will point at head,
        // lastodd helps in even no of nodes
        ListNode *odd = head, *oddhead = head, *lastodd = NULL;
        // even,even head strats from second node
        ListNode *even = head->next, *evenhead = head->next;
        while (odd && even)
        {
            // Linking odd's next with even next
            // Saving this odd as prev and moc=ving to new odd
            odd->next = even->next;
            lastodd = odd;
            odd = odd->next;
            // If current odd is NULL we'll break as we wont be able to link even
            if (!odd)
                break;
            // else we linkeven's next to odd next
            even->next = odd->next;
            // And only if even is not null we move even ahead
            if (even)
                even = even->next;
        }
        // If odd exists we link it with even head
        if (odd)
        {
            odd->next = evenhead;
        }
        // Idf odd has become null we use lastodd
        else
        {
            lastodd->next = evenhead;
        }
        return head;
    }
};
