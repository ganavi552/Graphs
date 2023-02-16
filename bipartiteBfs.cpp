#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool checkBipartite(int V,vector<int>adj[]){
        vector<int>vis(V,-1);
        queue<int> q;
        q.push(1);
        vis[1]=0;
        while(!q.empty()){
            int node=q.front();
            int v=vis[node];
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==-1){//condition for checting the node has color or not
                    vis[it]=1-vis[node];
                    q.push(it);
                }else if(vis[it]==vis[node]){//condition for checking whether the node and its adjacent node colored with same color or not.
                   return false;
                }
            }
        }
        return true;
    }
};
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[9];
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,2,7); 
    addEdge(adj,7,6);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,5,8);
    Solution obj;
    int ans=obj.checkBipartite(8,adj);
    if(ans==1)
    cout<<"Yes";
    else
    cout<<"No";

}