#include<bits/stdc++.h>
using namespace std;
class Solution{
   void findTopoSort(vector<int>& vis,int i,vector<int> adj[],stack<int>& st){
          vis[i]=1;
          for(auto it:adj[i]){
            if(vis[it]==0){
                findTopoSort(vis,it,adj,st);
            }
          }
          st.push(i);
    }
  public:
     vector<int> topoSort(int N,vector<int> adj[]){
        vector<int> vis(N,0);
        stack<int> st;
        for(int i=0;i<N;i++){
            if(vis[i]==0){
                findTopoSort(vis,i,adj,st);
            }
        }
        vector<int> topo;
        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
     }

};
void printAns(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    vector<int> adj[6];
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[5].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[4].push_back(1);
    
    
    Solution obj;
    vector<int> ans=obj.topoSort(6,adj);
   printAns(ans);

}