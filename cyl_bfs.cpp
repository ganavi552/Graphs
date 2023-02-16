#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool checkForCycle(int i,int V,vector<int> adj[],vector<int>&vis){
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i]=1;
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(par != it){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V,vector<int> adj[]){
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkForCycle(i,V,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    // vector<int> adj[12];
    // addEdge(adj,1,2);
    // addEdge(adj,2,4);
    // addEdge(adj,3,5);
    // addEdge(adj,5,6);
    // addEdge(adj,5,10);
    // addEdge(adj,6,7);
    // addEdge(adj,10,9);
    // addEdge(adj,9,8);
    // addEdge(adj,7,8);
    // addEdge(adj,8,11);
   

    vector<int> adj[5];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
     // addEdge(adj,1,3);
    //addEdge(adj,1,4);
   
    
    Solution obj;
     // int n=obj.isCycle(12,adj);
    int n=obj.isCycle(5,adj);
    if(n==1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
