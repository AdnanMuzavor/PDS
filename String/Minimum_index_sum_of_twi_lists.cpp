/*
599. Minimum Index Sum of Two Lists
Easy

1099

313

Add to List

Share
Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.



Example 1:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:

Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> m;
        vector<string> op;
        int i = 0, minval = INT_MAX;
        for (auto e : list1)
        {
            m[e] = i + 1;
            i++;
        }
        i = 0;
        for (auto e : list2)
        {
            if (m[e] && i + (m[e] - 1) != minval)
            {

                int indexsum = i + (m[e] - 1);
                minval = min(minval, indexsum);
            }

            i++;
        }
        i = 0;
        for (auto e : list2)
        {
            if (m[e] && i + (m[e] - 1) == minval)
            {
                op.push_back(e);
            }
            i++;
        }
        return op;
    }
};