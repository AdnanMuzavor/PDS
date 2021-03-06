/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //APPROACH-1
        //bruteforce approach->run 2 loops

        //APPROACH-II
        //Use extra space to keep track of max/min
        vector<int> v(prices.size(),INT_MAX);
        int minval=INT_MAX,maxval=-1;
        //Keeping track of minval
        //You can also prefer to take care of maxval
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minval){
                minval=prices[i];
            }
            v[i]=minval;
        }
        for(int i=0;i<prices.size();i++){
            if(prices[i]-v[i]>maxval){
                maxval=prices[i]-v[i];
            }
        }
        return maxval;

        //APPROACH-III
        //Keep track of profit
         int maxprofit=0;
        int minval=prices[0];
        for(int i=0;i<prices.size();i++){
            minval=min(minval,prices[i]);
            int profithere=prices[i]-minval;
            maxprofit=max(maxprofit,profithere);
        }
        return maxprofit;
    }
};