/*
389. Find the Difference
Easy

2422

366

Add to List

Share
You are given two strings s and t.

String t is generated by random shuffling string s and then add one more letter at a random position.

Return the letter that was added to t.



Example 1:

Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
Example 2:

Input: s = "", t = "y"
Output: "y"
*/
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         int l1=s.size(),l2=t.size();
//         unordered_map<char,int> m;
//         for(auto e:t){
//             m[e]++;
//         }
//         for(auto e:s){
//             m[e]--;
//         }
//         for(auto e:m){
//             if(e.second>=1){
//                 return e.first;
//             }
//         }
//         return '\0';
//     }
// };
//OPTIMISED
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        char r = 0;
        for (char c : s)
        {
            cout << "r before xoring with: " << c << " is: " << r << endl;
            r ^= c;
            cout << "r after xoring with: " << c << " is: " << r << endl;
        }
        for (char c : t)
        {
            cout << "r before xoring with: " << c << " is: " << r << endl;
            r ^= c;
            cout << "r after xoring with: " << c << " is: " << r << endl;
        }
        return r;
    }
};
