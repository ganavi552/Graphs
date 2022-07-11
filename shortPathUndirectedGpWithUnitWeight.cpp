#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void shortPath(int src,vector<int> adj[],int N){
        vector<int> dist(N,999);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[it]>dist[node]+1){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<N;i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
};
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    vector<int> adj[9];
    addEdge(adj,0,1);
    addEdge(adj,0,3);
    addEdge(adj,1,3);
    addEdge(adj,1,2);
    addEdge(adj,2,6);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,6);
    addEdge(adj,6,7);
    addEdge(adj,6,8);
    addEdge(adj,7,8);
    Solution obj;
    obj.shortPath(0,adj,9);
    cout<<endl;

}