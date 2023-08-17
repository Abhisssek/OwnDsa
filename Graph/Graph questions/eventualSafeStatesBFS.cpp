#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<int> eventualSafeNode(int v, vector<int> adj[]){
        vector<int> adjrev[v];
        int indegree[v]={0};
        for(int i=0;i<v;i++){
            for(auto it : adj[i]){
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
    
        queue<int>q;
        vector<int> safenodes;
        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it: adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    
        sort(safenodes.begin(),safenodes.end());
        return safenodes;

    }

};


int main(){
   vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
    
    int v=12;
    solution obj;
    vector<int> safenodes=obj.eventualSafeNode(v,adj);

    for(auto node: safenodes){
        cout<<node<<" ";

    }
    cout<<endl;
    return 0;
}