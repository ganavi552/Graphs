#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"enter value for m and n ";
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    int u,v,w;
    for(int i=0;i<m;i++){
       cout<<"enter value for u v w "<<endl;
       cin>>u>>v>>w;
       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
    }
    vector<int> key(n,999);
    vector<bool> mst(n,false);
    vector<int> parent(n,-1);
    key[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});//weight,index
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        mst[u]=true;
        for(auto it:adj[u]){
            int n=it.first;
            int w=it.second;
            if(mst[n]==false && key[n]>w){
                parent[n]=u;
                key[n]=w;
                pq.push({key[n],n});
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-"<<i<<"\n";
    }
    return 0;
}