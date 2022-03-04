/*
392. Is Subsequence
Easy

3854

270

Add to List

Share
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).



Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        // If both are equal
        if (s == t)
            return true;
        int n1 = s.size();
        int n2 = t.size();
        // If t size< s size thn s cannot be formed from t
        if (n2 < n1)
            return false;
        string res = "";
        int j = 0;
        // Traversing string s and finding match in t as indexs afre to be as per order
        for (int i = 0; i < n1; i++)
        {
            // We try finding one character
            while (j < n2 && s[i] != t[j])
            {
                j++;
            }
            // We append that char to string and move j ahead to find next char same as s[i]
            if (j < n2)
                res += t[j];

            j++;
        }
        cout << res << endl;
        // If res!=s means string could'nt be form
        if (res != s)
            return false;
        return true;
    }
};
//Instead of string usig a constant variable instead
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //If both are equal
        if(s==t) return true;
        int n1=s.size();
        int n2=t.size();
        //If t size< s size thn s cannot be formed from t
        if(n2<n1) return false;
       // string res="";
        int res=0;
        int j=0;
        //Traversing string s and finding match in t as indexs afre to be as per order
        for(int i=0;i<n1;i++){
            //We try finding one character
            while(j<n2 && s[i]!=t[j]){
                j++;
            }
            //We append that char to string and move j ahead to find next char same as s[i]
            if(j<n2) res+=1;
           
            j++;
        }
       
        //If res!=s means string could'nt be form
        if(res!=n1) return false;
        return true;
    }
};