#include<bits/stdc++.h>
using namespace std;

class solution{
    private:
    void dfs(int node, int vis[], stack<int>& st, vector<int> adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]) dfs(it,vis,st,adj);
        }
        st.push(node);
    }

    public:
    vector<int> toposort(int v, vector<int> adj[]){
        int vis[v]={0};
        stack<int> st;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }   

        return ans;
    }
};


int main(){
    vector<int> adj[6]={{},{},{3},{1},{0,1},{0,2}};
    int v=6;
    solution obj;
    vector<int> ans= obj.toposort(v,adj);
    for(auto node: ans){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;

}