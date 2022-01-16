/*
876. Middle of the Linked List
Easy

4359

110

Add to List

Share
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.



Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
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
    ListNode *middle(ListNode *r)
    {
        ListNode *ptr = r;
        int l = 0;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            l++;
        }
        cout << l << endl;
        int mid = l / 2;
        cout << mid << endl;
        ptr = r;
        while (mid--)
        {
            ptr = ptr->next;
        }
        return ptr;
    }
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        return middle(head);
    }
};

//Best soln
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       vector<ListNode*> v;
        while(head!=NULL){
            v.push_back(head);
            head=head->next;
        }
        return v[v.size()/2];
    }
};