#include<bits/stdc++.h>
using namespace std;
void dijkstras(int src,int N,vector<pair<int,int>>adj[]){
    vector<int> dist(N,999);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        int d=pq.top().first;
        int n=pq.top().second;
        pq.pop();
        for(auto it:adj[n]){
            if(dist[it.first] > d+it.second ){
                dist[it.first]= d+it.second;
                pq.push({dist[it.first],it.first});
            }
        }

    }
    for(int i=1;i<N;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

}
void addEdge(vector<pair<int,int>>adj[],int u,int v,int w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}
int main(){
    vector<pair<int,int>> adj[6];
    addEdge(adj,1,2,2);
    addEdge(adj,1,4,1);
    addEdge(adj,4,3,3);
    addEdge(adj,2,3,4);
    addEdge(adj,2,5,5);
    addEdge(adj,3,5,1);
    dijkstras(1,6,adj);
    cout<<endl;

}