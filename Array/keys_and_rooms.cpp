/*
841. Keys and Rooms
Medium

2756

166

Add to List

Share
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.



Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation:
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_map<int, int> m;
        // Initially marking all unvisited
        for (int i = 0; i < rooms.size(); i++)
        {
            m[i] = -1;
        }
        // Marking index 0 as visited
        m[0] = 1;
        // Using queue to keep track of keys
        queue<int> q;

        // Initialising queue by pushing keys as index=0 which we could visit
        for (auto e : rooms[0])
        {
            q.push(e);
        }
        // If first room had no keys we cannot visit any other room hence false
        if (q.empty())
            return false;

        while (!q.empty())
        {
            // push keys of visited room only
            int i = q.front();
            q.pop();
            // If thsi popped index was not visited
            if (m[i] == -1)
            {

                m[i] = 1; // Making it visited
                // Since we are able to visit room[i], we push all keys of room i
                for (auto e : rooms[i])
                    q.push(e);
            }
        }
        // If at all any room is unvisited i.e -1, we return false
        for (auto e : m)
        {
            if (e.second == -1)
                return false;
        }
        return true;
    }
};
// Efficient way of writing same code
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        unordered_set<int> visited;
        queue<int> to_visit;
        to_visit.push(0);
        while (!to_visit.empty())
        {
            int curr = to_visit.front();
            to_visit.pop();
            visited.insert(curr);
            for (int k : rooms[curr])
                if (visited.find(k) == visited.end())
                    to_visit.push(k);
        }
        return visited.size() == rooms.size();
    }
};
