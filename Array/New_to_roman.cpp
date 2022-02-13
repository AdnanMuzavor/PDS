/*
12. Integer to Roman
Medium

2772

3795

Add to List

Share
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.



Example 1:

Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include <bits/stdc++.h>
using namespace std;
// OPTIMISED AND EASY TO UNDERSTAND
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        // SOLN-2 AS PERNEETCODE EXPLAINATION
        sort(intervals.begin(), intervals.end());
        int prevend = intervals[0][1]; // Keeping track of first end
        int ans = 0;
        // Iterating from index 1, if starting val is >=pre interval end value
        // eg [1,2]][2,3] then they won't overlap
        // so we update prevend to new end  i.e 3
        // else eg [1,2][1,3] here we know since 1<2 it'll overlap
        // So it's like we choose to remove one with higher end value
        // Here[1,3]since it has chances of further iverlapping with more intervals
        // This is done by maintaing prevend =min(prevend,cuurrelement[1]) i.e
        // preend=min(prevend =2, currele[1] i.e 3)
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= prevend)
            {
                prevend = intervals[i][1];
            }
            else
            {
                ans++;
                prevend = min(prevend, intervals[i][1]);
            }
        }
        return ans;
    }
};
// BRUTE FORCE
class Solution
{
public:
    string intToRoman(int num)
    {

        string soln = "";
        if (num <= 3)
        {
            while (num--)
                soln += "I";
            return soln;
        }
        // Making symbol verses string table
        // With help of hashmap for easy access
        // And taking care of additional cases as given
        // i.e 4,9,40,90,400,900
        //  vector<pair<int,string>> table(12);
        vector<pair<int, string>> table = {make_pair(1000, "M"), make_pair(900, "CM"), make_pair(500, "D"), make_pair(400, "CD"), make_pair(100, "C"), make_pair(90, "XC"), make_pair(50, "L"), make_pair(40, "XL"), make_pair(10, "X"), make_pair(9, "IX"), make_pair(5, "V"), make_pair(4, "IV")};

        int i = 0; // That is we'll first be checking with largest number
        // as it is roman numbers law
        while (num > 0)
        {
            if (num <= 3)
            {
                while (num--)
                    soln += "I";
                num = num / 10;
                continue;
            }
            if (num == 6)
            {
                soln += "VI";
                num = num / 10;
                continue;
            }
            else if (num == 7)
            {
                soln += "VII";
                num = num / 10;
                continue;
            }
            else if (num == 8)
            {
                soln += "VIII";
                num = num / 10;
                continue;
            }
            int val = num / table[i].first;
            // cout<<"val: "<<val<<" and / by: "<<table[i].first<<endl;
            if (val <= 0)
            {
                i++;
                // cout<<"i : "<<i<<endl;
                continue;
            }
            while (val--)
            {
                soln += table[i].second;
            }
            num = num % table[i].first;
            i++;
        }
        return soln;
    }
};
// CLEAN CODE
class Solution
{
public:
    string intToRoman(int num)
    {
        string res;
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        for (int i = 0; num != 0; i++)
        {
            while (num >= val[i])
            {
                num -= val[i];
                res += sym[i];
            }
        }

        return res;
    }
};