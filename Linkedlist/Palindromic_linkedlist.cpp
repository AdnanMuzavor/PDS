/*
234. Palindrome Linked List
Easy

7730

500

Add to List

Share
Given the head of a singly linked list, return true if it is a palindrome.



Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
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
// O(N)+O(N)
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
            return true;
        stack<ListNode *> s;
        ListNode *p = head;
        // given [1,2,3,2,1]
        // pushing into stack [1,2,3,2,1]
        // moving p back to head
        // comparing elements with stack top
        // If same pop-out
        // else return false

        // STEP-1 Push into the stack
        while (p)
        {
            s.push(p);
            p = p->next;
        }
        // STEP-2 Move p back to head
        p = head;
        while (!s.empty())
        {
            // If palindrome last element which is at top of stack
            // will be same as first element i.e p
            // And so on as we move p
            if (s.top()->val == p->val)
            {
                s.pop();
            }
            else
            {
                return false;
            }
            p = p->next;
        }
        if (s.empty())
            return true;
        return false;
    }
};
// O(N)+O(1)

class Solution
{
public:
    ListNode *rev(ListNode *h)
    {
        ListNode *curr = h;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *dummy = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = rev(slow->next);
        slow = slow->next;
        while (slow)
        {
            if (dummy->val != slow->val)
            {
                return false;
            }
            dummy = dummy->next;
            slow = slow->next;
        }
        return true;
    }
};