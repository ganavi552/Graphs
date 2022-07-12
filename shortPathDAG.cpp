#include<bits/stdc++.h>
using namespace std;
class Solution{
    void findShortPath(int i,vector<int>& vis,stack<int>& st,vector<pair<int,int>> adj[]){
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it.first]==0){
              findShortPath(it.first,vis,st,adj);  
            }
        }
        st.push(i);
    }
    public:
    void shortestPath(int src,int N,vector<pair<int,int>> adj[]){
        stack<int> st;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++){
            if(vis[i]==0){
                findShortPath(i,vis,st,adj);
            }
        }
        vector<int> dist(N,999);
        dist[src]=0;// As we are setting dist[src] = 0, it will start from there, the condition dis[node] != infinity will not let any  node other than src enter that condition first. Because of topological sort nodes coming before src will be discarded.
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(dist[node]!=999){
                for(auto it:adj[node]){
                    if(dist[node]+it.second<dist[it.first]){
                        dist[it.first]=dist[node]+it.second;
                    }
                }
            }
        }
        for(int i=0;i<N;i++){
            cout<<dist[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
    int n,m;//n->no of nodes.m->no of edges
    cout<<"enter n and m values";
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    int u,v,w;
    for(int i=0;i<m;i++){
        cout<<"enter value for u v w"<<endl;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    Solution obj;
    obj.shortestPath(0,n,adj);
    
    
}
// For all who are wondering the intution behind Topological sorting and why haven't we use simple DFS or BFS from the source node instead .
// READ THIS.................

// lets say you want to do it using DFS
// yes you can do it using DFS , but consider the case when you already updated a node's distance by a dfs() call and lets say its 7 and as it is DFS then its obvious that you also have updated all the nodes in its segment of DFS call . now you have reached to the same node from different dfs() call and now the distance is 4 , so in order to update all the nodes which were affected by the DFS call previously on the node considering distance as 7 , you now again have to do the same so that its updated with new min distance.
// Same is the scenario for the simple BFS approach.
// This multiple time calling DFS/BFS degrades the Time Complexity, hence Topological Ordering save you from that overhead as you already know which nodes will come after the current node , so you keep on updating it .



// If you are still confused with intution behind the topological sort....
// Topological sort ensures that we are picking up nodes that come first while travelling from the source, this, in turn, will ensure that every node will have at least one condition that it can be reached from the source.
// As we are setting dist[src] = 0, it will start from there, the condition dis[node] != infinity will not let any  node other than src enter that condition first. Because of topological sort nodes coming before src will be discarded.