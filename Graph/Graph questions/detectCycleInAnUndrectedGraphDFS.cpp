#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis[],vector <int> adj[]){
    vis[node]=1;
    for(auto adjnode:adj[node]){
        if(!vis[adjnode]){
            if(dfs(adjnode,node,vis,adj)==true){
                return true;
            }
        }
        else if(adjnode!=parent){
            return true;
        }
        
    }
    return false;
}


bool iscycle(int v, vector<int> adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)==true){
                return true;
            }
        }

    }
    return false;
}


int main(){
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    bool ans=iscycle(4,adj);
    if(ans){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}