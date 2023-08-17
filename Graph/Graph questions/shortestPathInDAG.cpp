#include<bits/stdc++.h>
using namespace std;

class solution{
    private:
    void toposort(int node,vector<pair<int,int>> adj[], int vis[], stack<int>& st){
        vis[node]=1;
        for(auto it: adj[node]){
            int v=it.first;
            if(!vis[v]){
                toposort(v,adj,vis,st);
            }
        }
        st.push(node);
    }


    public:
    vector<int> shortestpath(int n, int m, vector<vector<int>> & edges){
        vector<pair<int,int>> adj[n];
        for(int i=0; i<m; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];

            adj[u].push_back({v,wt});
        }

        int vis[n]={0};

        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                toposort(i,adj,vis,st);
            }
        }

        vector<int> dist(n);
        for(int i=0;i<n;i++){
            dist[i]=1e9;
        }

        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto it: adj[node]){
                int v= it.first;
                int wt=it.second;

                if(dist[node]+wt<dist[v]){
                    dist[v]=wt+dist[node];
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};

int main(){
    int n=6,m=7;
    vector<vector<int>> edges={{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    solution obj;
    vector<int> ans=obj.shortestpath(n,m,edges);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}