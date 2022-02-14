/*
415. Add Strings
Easy

2897

519

Add to List

Share
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {

        // SOLN-2 DOESN'T WORKS
        //          long long int n1=0,n2=0;
        //          for(auto e:num1){
        //              n1=n1*10+(long long int)(e-'0');
        //             // cout<<n1<<endl;
        //          }
        //          for(auto e:num2){
        //              n2=n2*10+(long long int)(e-'0');
        //             // cout<<n2<<endl;
        //          }

        //         return to_string(n1+n2);
        // Result here
        string res = "";
        // Starting from back
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0; // to keep tract of carry
        while (i >= 0 || j >= 0)
        {
            int sum = carry + (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
            carry = (sum >= 10) ? sum / 10 : 0;
            sum = sum % 10;
            res = res + to_string(sum);
            i--;
            j--;
        }
        if (carry >= 1)
        {
            res += to_string(carry);
        }
        reverse(res.begin(), res.end());
        return res;
        // return "";
    }
};