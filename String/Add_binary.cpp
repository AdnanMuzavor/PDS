/*
67. Add Binary
Easy

4641

516

Add to List

Share
Given two binary strings a and b, return their sum as a binary string.



Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        // Vectors to keep string values
        vector<int> n1;
        vector<int> n2;
        // string sizes
        int ns1 = a.size();
        int ns2 = b.size();
        // Making both of equal length
        if (ns1 != ns2)
        {
            if (ns1 > ns2)
            {
                string newb = "";
                int diff = ns1 - ns2;
                // Appending zeros in front
                while (diff--)
                {
                    newb += "0";
                }
                newb += b;
                b = newb;
            }
            else
            {
                string newa = "";
                int diff = ns2 - ns1;
                // Appending zeros in front
                while (diff--)
                {
                    newa += "0";
                }
                newa += a;
                a = newa;
            }
        }
        // Making integer of given binary
        for (auto e : a)
        {
            n1.push_back(e - '0');
        }
        for (auto e : b)
        {
            n2.push_back(e - '0');
        }

        vector<int> res(n1.size() + 1, 0);

        // Basically adding both  vals such that other vector has one size extra
        for (int i = n1.size() - 1; i >= 0; i--)
        {

            res[i + 1] = n1[i] + n2[i];
        }

        int c = 0;
        for (int i = res.size() - 1; i >= 1; i--)
        {
            // Finding carry to be passed to value on left
            int carry = res[i] / 2;
            // Updating current value
            res[i] = res[i] % 2;
            // Updating previous value by adding carry
            res[i - 1] = res[i - 1] + carry;
            // Updating c so as to decide first(0th) index value
            c = carry;
        }
        string ans = "";
        if (c == 1)
        {
            res[0] = 1;
            // If res[0]==1 it'll be considered in ans
            for (auto e : res)
            {
                ans += to_string(e);
            }
        }
        else
        {
            res[0] = 0;
            // Ele it wont be considered in ans
            for (int i = 1; i < res.size(); i++)
            {
                ans += to_string(res[i]);
            }
        }

        return ans;
    }
};

// O(N+N=N)
class Solution
{
public:
    string addBinary(string a, string b)
    {

        // string sizes
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carry)
        {
            if (i >= 0)
            {
                carry += (a[i] - '0');
                i--;
            }
            if (j >= 0)
            {
                carry += (b[j] - '0');
                j--;
            }
            ans += ((carry % 2) + '0');
            carry = carry / 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};