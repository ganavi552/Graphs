#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> topoSort(int N,vector<int> adj[]){
        queue<int> q;
        vector<int>indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }     
            }
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