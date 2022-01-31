/*
2130. Maximum Twin Sum of a Linked List
Medium

245

14

Add to List

Share
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.



Example 1:


Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6.
Example 2:


Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7.
Example 3:


Input: head = [1,100000]
Output: 100001
Explanation:
There is only one node with a twin in the linked list having twin sum of 1 + 100000 = 100001.
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
//O(N)+O(N)
class Solution
{
public:
    // To find length
    int len(ListNode *h)
    {
        ListNode *p = h;
        int l = 0;
        while (p)
        {
            p = p->next;
            l++;
        }
        return l;
    }
    int pairSum(ListNode *head)
    {
        // To find mid value
        long long int mid = len(head) / 2;
        long long int n = mid, i = 0;
        ListNode *p = head;
        vector<ListNode *> twin;

        // Move pointer to mid node
        //[5,4,2,1]

        // pointer initially at 5, p->5
        while (mid--)
            p = p->next;
        // pointer finally at 2, p->2

        // From mid node start pushing elements into the stack
        while (p)
        {
            twin.push_back(p);
            p = p->next;
        }
        // original: [5,4,2,1]
        // twin :    [2,1]

        // Reverse twin array so as to make twins coincide with respective nodes
        reverse(twin.begin(), twin.end());
        // After reversing
        // Original: [5,4,2,1]
        // twin:     [1,2]
        // i.e 5's twin is 1
        // i.e 4's twin is 2

        p = head;
        long long int maxi = INT_MIN;

        // Now we can add them and get the maximum value
        while (n--)
        {

            if (p->val + twin[i]->val > maxi)
            {
                maxi = p->val + twin[i]->val;
            }
            p = p->next;
            i++;
        }

        return maxi;
    }
};

//O(N)+O(1)
class Solution {
public:
    //To find length
    int len(ListNode*h){
        ListNode*p=h;
        int l=0;
        while(p){
            p=p->next;
            l++;
        }
        return l;
    }
    ListNode* rev(ListNode*h){
        ListNode* curr=h,*prev=NULL,*nextt=NULL;
        while(curr){
            nextt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextt;
            
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        //To find mid value
        long long int mid=len(head)/2,maxi=INT_MIN;
        long long int n=mid,i=0;
        ListNode*p=head;
        //Moving to mid pointer
        while(mid--)p=p->next;
        //Revering LL by taking mid as head
        p=rev(p);
        
        //Adding respective twins and updating maximum var
        while(p){
            if(p->val+head->val>maxi){
                maxi=p->val+head->val;
            }
            head=head->next;
            p=p->next;
        }
        return maxi;
       

    }
};