/*
1171. Remove Zero Sum Consecutive Nodes from Linked List
Medium

1283

66

Add to List

Share
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.



(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        // First two nodes can also give sum 0
        // Hence to prevent confusion we make
        // A dummy node which will be placed before head node
        ListNode *d = new ListNode(0);
        d->next = head;
        ListNode *prev = d;
        while (head)
        {
            // Checking from current head
            int sum = head->val;
            ListNode *p = (head) ? head->next : NULL;
            // Traverse till we get sum=0 or reach end
            while (p && sum != 0)
            {

                sum += p->val;

                p = p->next;
            }
            // if sum =0 means this consecutive sequence
            // right from head to p->prev is causing 0
            // So we get rif of this part by pointing
            // prev->next to p
            if (sum == 0)
            {

                prev->next = p;
                head = p;
                if (prev->next == NULL)
                    break;
            }
            // if sum!=0 thn we move prev to next
            // and we also update head
            else
            {
                if (prev->next)
                    prev = prev->next;
                head = head->next;
            }
            // Ding this is invalid coz suppose
            // you have seq=[1,-1,2,-2]
            // After deletion prev->next will be 2
            // doing head=head->next will move head directly to -2
            // so 2+-2=0 won't be comsider giving wrong answer
            //  head =head->next;
        }
        return d->next;
    }
};

// O(N)+O(N)
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        dummy->next = head;
        int prefix = 0;
        map<int, ListNode *> m;
        while (cur)
        {
            prefix += cur->val;
            if (m.count(prefix))
            {
                cur = m[prefix]->next;
                int p = prefix + cur->val;
                while (p != prefix)
                {
                    cout << "earsing: " << p << endl;
                    m.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                m[prefix]->next = cur->next;
            }
            else
            {
                m[prefix] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};