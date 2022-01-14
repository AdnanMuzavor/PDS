
/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long int nr=1,n=1;
    long long int dr=1,r=0;
    int giveelement(){
        cout<<n<<" C "<<r<<endl;
        nr=nr*n;
        dr=dr*r;
        n--;
        r++;
        cout<<nr/dr<<" "<<endl;
        return nr/dr;
    }
    vector<int> getRow(int rowIndex) {
        
        //BRUTE FORCE
      //   vector<int> op;
      //   op.push_back(1);
      //   if(rowIndex==0) return op;
      //   n=rowIndex;
      //   r=1;
      //   int i=1;
      //   while(i<rowIndex && i<=rowIndex/2){
      //       i++;
      //       op.push_back(giveelement());
      //   }
      //   cout<<"row"<<endl;
      //   cout<<op[i-1]<<endl;
      // if(rowIndex%2!=0){
      //       for(int j=i-1;j>=1;j--){
      //           op.push_back(op[j]);
      //       }
      //   }
      //   else{
      //        for(int j=i-2;j>=1;j--){
      //           op.push_back(op[j]);
      //       }
      //   }
      //   nr=1,n=1,dr=1,r=0;
      //   op.push_back(1);
      //   return op;
        
        
        vector<vector<int>> res;
        for(int i=0;i<=rowIndex;i++){
            vector<int> r(i+1,1);
            for(int j=1;j<i;j++){
                r[j]=res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(r);
        }
        return res[rowIndex];
        
    }
};