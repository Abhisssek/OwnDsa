#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjLS[],int vis[]){
    vis[node]=1;
    for(auto it: adjLS[node]){
        if(!vis[it]){
            dfs(it,adjLS,vis);
        }
    }
}

int numprovinces(vector<vector<int>> adj, int v){
    vector<int> adjLs[v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==1&&i!=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    int vis[v]={0};
    int cnt=0;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjLs,vis);
        }
    }
    return cnt;
}


int main(){
    vector<vector<int>> adj={{1,0,1},
                            {0,1,0},
                            {1,0,1}};
    cout<<numprovinces(adj,3)<<endl;
    return 0;
}