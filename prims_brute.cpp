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
    for(int i=0;i<n-1;i++){
        int min=999,v;
        for(int u=0;u<n;u++){
            if(mst[u]==false && key[u]<min){
                min=key[u];
                v=u;
            }
        }
        mst[v]=true;
        for(auto it:adj[v]){
            int n = it.first;
            int d = it.second;
            if(mst[n]==false && d<key[n]){
                 parent[n]=v;
                 key[n]=d;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout<<parent[i]<<"-"<<i<<"\n";
    }
    return 0;
}