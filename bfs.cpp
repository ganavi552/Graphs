#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
     vector<int> bfsOfGraph(int V,vector<int> adj[]){
        vector<int> bfs;
        vector<int> v(V,0);
        queue <int> q;
        q.push(0);
        v[0]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node]){
               if(!v[it]){
                q.push(it);
                v[it]=1;
               }
            }
        }
        return bfs;
     }
};
void printAns(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[5];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,0,3);
    addEdge(adj,2,4);
    Solution obj;
    vector<int> ans=obj.bfsOfGraph(5,adj);
    printAns(ans);
    cout<<endl;

}