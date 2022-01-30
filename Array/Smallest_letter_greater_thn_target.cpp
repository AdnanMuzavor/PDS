/*
744. Find Smallest Letter Greater Than Target
Easy

1278

1209

Add to List

Share
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.


Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Example 3:

Input: letters = ["c","f","j"], target = "d"
Output: "f"
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        cout << 'a' - 'z' << endl;
        // Incase letters are ["a","b"] and target is z
        // Thn after z if we go clock wise ,what comes next is
        //"a" i.e letters[0] nut however "a"-"z" is negative so soln won;t get updated in loop
        // And letters[0] will be our ans
        char sol = letters[0];
        int min = INT_MAX;
        for (int i = 0; i < letters.size(); i++)
        {
            // If current char >target and differnec is minimum thn
            // Update the minimum and soln value
            if (letters[i] - target > 0 && letters[i] - target < min)
            {
                min = letters[i] - target;
                sol = letters[i];
            }
        }
        return sol;
    }
};