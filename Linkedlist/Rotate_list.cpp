/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* h){
        ListNode*p=h;
        int l=0;
        while(p!=NULL){
            p=p->next;
            l++;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(length(head)==1 || length(head)==0 || k==0 ||k==length(head)) return head;
        k=k%length(head);
        if(k==0) return head;
        int l=length(head)-k;
        ListNode *p=NULL,*q=NULL; 
        //q for pointing last node and p for pointing new head
        p=head;
        while(l--){
            q=p;
            p=p->next;
        }
       // cout<<q->val<<" "<<p->val<<endl;
        q->next=NULL;
        
        //To traverse till end of detached LL
        ListNode*r=p;
        while(r->next!=NULL) r=r->next;
        
        //Attaching last node of detached LL with old head
        r->next=head;
        
        //Getting new head
        head=p;
        return head;
    }
};