/*
147. Insertion Sort List
Medium

1887

782

Add to List

Share
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.




Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
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

//Original code (Clean code at bottom)->with explaination
ListNode *insertionSortList(ListNode *head)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = head;
    ListNode *pb = head;
    ListNode *curr = head->next;
    while (curr)
    {
        cout << "curr val: " << curr->val << endl;
        cout << "prev val: " << prev->val << endl;
        cout << "pb val: " << pb->val << endl;
        if (curr->val <= pb->val)
        {
            // cout<<curr->val<<" < = "<<pb->val<<endl;
            // curr=insertion(prev,curr,pb);
            // //curr=curr->next;
            ListNode *nxt = curr->next, *prevbefore = pb;
            if (curr->val <= prev->val)
            {
                // cout<<"setting: "<<curr->val<<" ->next to "<<prev->val<<endl;
                curr->next = prev;
                prev = curr;
                // cout<<"new prev is: "<<prev->val<<endl;
                curr = nxt;
                // cout<<"new current is: "<<curr->val<<endl;
                prevbefore->next = curr;
                // cout<<"setting "<<prevbefore->val<<" ->next to: "<<curr->val<<endl;
            }
            else
            {

                cout << "curr val" << curr->val << " lies between" << prev->val << " - " << pb->val << endl;

                ListNode *q = prev, *p = prev->next;
                while (p != NULL && curr && p->val <= curr->val)
                {
                    q = p;
                    p = p->next;
                }
                if (q && p)
                    cout << q->val << " - " << p->val << endl;
                q->next = curr;
                curr->next = p;
                ListNode *prevcurr = curr;
                curr = nxt;
                if (pb->next == prevcurr)
                    pb->next = curr;
            }
        }
        else
        {
            pb = curr;
            curr = curr->next;
        }
        // display(prev);
        //  curr=curr->next;
    }
    // cout << "prev val: " << prev->val << endl;
    return prev;
}

 ListNode *insertionSortList(ListNode *head)
{
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = head;
    ListNode *pb = head;
    ListNode *curr = head->next;
    while (curr)
    {   
    //From node prev-to node pb we'll be having sorted linkedlist
    //Hence if curr->val <= pb->val means this node will be inserted in 
    //sorted linkedlist so we get inside
        if (curr->val <= pb->val)
        {
            //Keeping in record, curr->next node and last node of sorted LL i.e pb
            ListNode *nxt = curr->next, *prevbefore = pb;
            //Case where node will be inserted to fromt of sorted linkedlist
            if (curr->val <= prev->val)
            {
                //Since prev is head of sorted LL we make curr->next=prev
                curr->next = prev;
                //We make curr node as new head of sorted LL
                prev = curr;
               //We move curr to curr->next node which is stored in nxt
                curr = nxt;
                //Sinc ecurr node was linkd to pb, we make pb point to new current node
                prevbefore->next = curr;
                
            }
            else
            {
               
                //Else we'll be inserting value somewhere in between of sorted linkedlist
                ListNode*q=prev,*p=prev->next;
                while(p!=NULL && curr && p->val<=curr->val){
                    q=p;
                    p=p->next;
                }
                //Finding q and p which are nodes brtween which curr will lie
                if(q && p)cout<<q->val<<" - "<<p->val<<endl;
                //Placing curr in between this two nodes
                q->next=curr;
                curr->next=p;
                //Befpre changing curr storing it as as to connect connect pb->next with new curr
                ListNode*prevcurr=curr;
                //Changing current to new current
                curr=nxt;
                //Linking pb->next to new current
                if(pb->next==prevcurr) pb->next=curr;
                
              
            }
        }
        //Else if val> last node of sorted linkedlist we'll insert it in
        //soryted LL simple by moving pb ahead and travserse next remianing node
        else
        {
            pb = curr;
            curr = curr->next;
        }
        
    }
  
    return prev;
}
    
    
