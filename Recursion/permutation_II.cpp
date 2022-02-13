/*
47. Permutations II
Medium

4317

89

Add to List

Share
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include <bits/stdc++.h>
using namespace std;
//Approach 3 made more efficient by avoiding duplicate vals

class Solution {
public:
    map<vector<int>,int> m;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> op;
        if(nums.size()==1){
            op.push_back(nums);
            return op;
        }
        perm(nums,0,op);
        return op;
    }
    void perm(vector<int>v,int begin,vector<vector<int>> &op){
        if(begin>=v.size()){
         
              if(!m[v]){
              m[v]++;    
            op.push_back(v);
              }
          
            return;
        }
        for(int i=begin;i<v.size();i++){
            if(i!=begin && v[i]==v[i-1])continue;
            swap(v[begin],v[i]);
            perm(v,begin+1,op);
            swap(v[i],v[begin]);
        }
    }
};

// BRUTE FORCE APPROACH
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> op;
        if (nums.size() == 1)
        {
            op.push_back(nums);
            return op;
        }
        perm(nums, 0, op);
        return op;
    }
    void perm(vector<int> v, int begin, vector<vector<int>> &op)
    {
        if (begin >= v.size())
        {
            if (find(op.begin(), op.end(), v) == op.end())
            {
                op.push_back(v);
            }
            return;
        }
        for (int i = begin; i < v.size(); i++)
        {
            swap(v[begin], v[i]);
            perm(v, begin + 1, op);
            swap(v[i], v[begin]);
        }
    }
};

// Better Approach(not best)

class Solution
{
public:
    map<vector<int>, int> m;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> op;
        if (nums.size() == 1)
        {
            op.push_back(nums);
            return op;
        }
        perm(nums, 0, op);
        return op;
    }
    void perm(vector<int> v, int begin, vector<vector<int>> &op)
    {
        if (begin >= v.size())
        {

            if (!m[v])
            {
                m[v]++;
                op.push_back(v);
            }
            return;
        }
        for (int i = begin; i < v.size(); i++)
        {

            swap(v[begin], v[i]);
            perm(v, begin + 1, op);
            swap(v[i], v[begin]);
        }
    }
};