#include<bits/stdc++.h>
using namespace std;

class solution{
    private:
    bool dfscheck(int node, vector<int> adj[], int vis[], int pathvis[], int check[]){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfscheck(it,adj,vis,pathvis,check)==true){
                    check[node]=0;
                    return true;
                }
            }

            else if(pathvis[it]){
                check[node]=0;
                return true;
            }
        }

        check[node]=1;
        pathvis[node]=0;
        return false;
    }

    public:
        vector<int> evensafeNodes(int v, vector<int> adj[]){
            int vis[v]={0};
            int pathvis[v]={0};
            int check[v]={0};

            vector<int> safenodes;
            for(int i=0;i<v;i++){
                if(!vis[i]){
                    dfscheck(i,adj,vis,pathvis,check);
                }
            }

            for(int i=0;i<v;i++){
                if(check[i]==1){
                    safenodes.push_back(i);
                }
            }
            return safenodes;
        }

};


int main(){
   vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};

    int v=12;
    solution obj;
    vector<int> safenodes=obj.evensafeNodes(v,adj);
    for(auto node: safenodes){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;
}