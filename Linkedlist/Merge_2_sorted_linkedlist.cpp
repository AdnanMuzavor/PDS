/*
21. Merge Two Sorted Lists
Easy

10010

964

Add to List

Share
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.



Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        if (!list1 && !list2)
            return NULL;
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *res = NULL;
        ListNode *curr = NULL;
        cout << p->val << " " << q->val << endl;
        while (p && q)
        {
            if (p->val <= q->val)
            {

                if (res == NULL)
                {
                    res = p;
                    curr = p;
                }
                else
                {
                    curr->next = p;
                    curr = curr->next;
                }
                p = p->next;
            }
            else
            {
                // cout<<"inserting : "<<q->val<<endl;
                if (res == NULL)
                {
                    res = q;
                    curr = q;
                }
                else
                {
                    curr->next = q;
                    curr = curr->next;
                }
                q = q->next;
            }
            // else if(!p){
            //     break;
            // }
            //  else if(!q){
            //      break;
            //  }
        }
        if (p)
        {
            cout << "p: " << p->val << endl;
            while (p != NULL)
            {
                // cout<<"inserting : "<<p->val<<endl;
                curr->next = p;
                curr = curr->next;
                p = p->next;
            }
        }
        if (q)
        {
            cout << q->val << endl;
            while (q)
            {
                //  cout<<"inserting : "<<q->val<<endl;
                curr->next = q;
                curr = curr->next;
                q = q->next;
            }
        }

        curr->next = NULL;
        return res;
    }
};

//Easy approach
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};