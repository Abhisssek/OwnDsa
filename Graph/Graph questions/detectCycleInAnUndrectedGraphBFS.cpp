#include<bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjnode: adj[node]){
            if(!vis[adjnode]){
                vis[adjnode]=1;
                q.push({adjnode,node});
            }
            else if(parent!=adjnode){
                return true;
            }
        }
    }
    return false;
}

bool iscycle(int v, vector<int> adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)){
                return true;
            }
        }

    }
    return false;
}

int main(){
    vector<int> adj[4]={{},{2},{1,3},{2}};
    bool ans=iscycle(4,adj);
    if(ans){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}


