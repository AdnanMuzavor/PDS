/*
886. Possible Bipartition
Medium

2117

51

Add to List

Share
We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.



Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/

#include <bits/stdc++.h>
using namespace std;

//Why concept works?
 //We can create a graph and relate it with coloring concept
        //eg for text case 1:
        //          1
        //         / \
        //        2   3
        //        \
        //         4
        //Hece possible to color graph without adjacent getting same colored
        //So possible to group (1,4),(2,3)
        //eg for text case 2:
        //          1
        //         / \
        //        2---3
        //Hence not possible to color graph with 2 different colors hence false;

 class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<int> adj[n+1];
        //Making adjacency list
        for(auto e:dislikes){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //Dsiplaying list if want
        for(int i=1;i<=n;i++){
            cout<<"node is: "<<i<<endl;
            cout<<"adj are: ";
            for(auto e:adj[i]) cout<<e<<" ";
            cout<<endl;
        }
        //Color to maintain 2 different groups
        vector<int> color(n+1,0);
        queue<int> q;
        for(int i=1;i<=n;i++){
            //If colored means visited so skip procedure
            if(color[i]!=0) continue;
            //Elese color it and color all it's adjacent too
            color[i]=1;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                //Visiting adjacent nodes
                for(auto e:adj[node]){
                    //If not colored,color it and push into queue
                    if(!color[e]){
                        color[e]=(color[node]==1?2:1);
                        q.push(e);
                    }
                    //if colore with same color return false
                    else if(color[e] && color[e]==color[node]) return false;
                }
            }
        }
        return true;
    }
};     

//Optimised way of writing same code but did'nt work

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

                queue<int> q;
        vector<int> color(n+1,0);
        for(int i=1;i<=n;i++){
            //If already colored
            if(color[i]!=0) continue;
            
            //If not colored color it 
            color[i]=1;
            q.push(i);
            
            //Visit all it's adjacent
            //->If not visisted make them visited using other color
            //->If visisted check if color is different from current node color
            
            while(!q.empty()){
                int node=q.front();
                q.pop();
                cout<<"node is: "<<node<<endl;
                //Getting elements adjacent to node
                for(auto e:dislikes){
                    if(e[0]==node){
                    //If colored check if color is same as color of node it's adjacent to
                    //if so return false
                    if(color[e[1]] && color[e[1]]==color[node]){
                            return false;
                        }
                    
                        //If adjacent is not colored, color it with opposite color
                      else if(!color[e[1]]){
                            color[e[1]]=(color[node]==1?2:1);
                            q.push(e[1]);
                        }
                    }
                }
            }
        }
        return true;
    }
};