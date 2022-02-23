/*
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Medium

207

8

Add to List

Share
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].



Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
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
// O(N+k)+O(k) k is no of criticalm points maintained in op array
// O(N+k) N for travsersing linkedlist
//        K for finding minimum distance
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> op;
        if (head && head->next && !head->next->next)
        {
            op.push_back(-1);
            op.push_back(-1);
            return op;
        }

        // Finding all critical points
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *nxt = curr->next;
        int index = 2;
        while (nxt)
        {
            // Got local maxima
            if (nxt->val < curr->val && prev->val < curr->val)
            {
                op.push_back(index);
                cout << "Local maxima found at: " << index << endl;
            }
            // Got local minima
            else if (nxt->val > curr->val && prev->val > curr->val)
            {
                op.push_back(index);
                cout << "Local minima found at index: " << index << endl;
            }
            prev = curr;
            curr = nxt;
            nxt = curr->next;
            index++;
        }
        cout << "Crtical points are: ";
        for (auto e : op)
        {
            cout << e << " ";
        }
        cout << endl;
        vector<int> finalop(2, -1);
        // If size<2 means only 1 critical point or no critical points exists
        // so we return -1,-1
        if (op.size() < 2)
            return finalop;

        // If only 2 critical poiny=ts found min/max dis will be same
        if (op.size() == 2)
        {
            finalop[0] = (abs(op[1] - op[0]));
            finalop[1] = (abs(op[1] - op[0]));
        }
        // If more then 2 critical points exists
        else
        {
            // WE know that maxval will beggivenn by first found critical point and last found critical point
            int maxval = op[op.size() - 1] - op[0];
            int minval = INT_MAX;
            ;
            // For min  distance since array is sorted we can find by subtraction
            for (int i = 1; i < op.size(); i++)
            {
                minval = min(minval, op[i] - op[i - 1]);
            }
            finalop[0] = minval;
            finalop[1] = maxval;
        }
        return finalop;
    }
};
// O(N) for traversing nodes
// O(1) space
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {

        // Finding all critical points
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *nxt = curr->next;
        // first critical point index
        int c1 = -1;
        // Last critical point index
        int c2 = -1;
        // Min diff everytime we find critical point
        int mindiff = INT_MAX;
        // To keep index of prev critical
        int prevc = -1;
        int index = 2;
        while (nxt)
        {
            // Got local maxima
            if (nxt->val < curr->val && prev->val < curr->val)
            {
                if (c1 == -1)
                    c1 = index; // Updating only when found first time
                c2 = index;     // Updating every time so that we have last critical index value
                // If prevc not initialised we won't be able to get diff
                if (prevc == -1)
                {
                    prevc = index;
                }
                // else we we calculate mindiff and update prev critical point
                else
                {
                    mindiff = min(mindiff, index - prevc);
                    prevc = index;
                }
            }
            // Got local minima
            else if (nxt->val > curr->val && prev->val > curr->val)
            {
                if (c1 == -1)
                    c1 = index; // Updating only when found first time
                c2 = index;     // Updating every time so that we have last critical index value
                // If prevc not initialised we won't be able to get diff
                if (prevc == -1)
                {
                    prevc = index;
                }
                // else we we calculate mindiff and update prev critical point
                else
                {
                    mindiff = min(mindiff, index - prevc);
                    prevc = index;
                }
            }
            prev = curr;
            curr = nxt;
            nxt = curr->next;
            index++;
        }

        vector<int> finalop(2, -1);
        // c1==-1means no critical point
        // c1==c2 means exactly one critical point
        if (c1 == -1 || prevc == -1 || c1 == c2)
            return finalop;
        finalop[0] = mindiff;
        finalop[1] = c2 - c1;
        return finalop;
    }
};