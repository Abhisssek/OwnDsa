#include<bits/stdc++.h>
using namespace std;

vector<int> bfsGraph(int v, vector<int>adj[]){
    int vis[v]={0};
    vis[0]=1;
    queue<int>q;
    q.push(0);

    vector<int>bfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;

}

void addedge(vector<int> adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printans(vector<int> ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    vector<int> adj[6];

    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,3);
    addedge(adj,0,4);

    vector<int> ans=bfsGraph(5,adj);
    printans(ans);
    return 0;

}