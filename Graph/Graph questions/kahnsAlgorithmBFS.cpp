#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<int> toposort(int v, vector<int> adj[]){
        int indegree[v]={0};
        for(int i=0; i<v; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<v; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
};

int main(){
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    int v=6;
    solution obj;
    vector<int> ans=obj.toposort(v,adj);
    for(auto node: ans){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}