#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    vector<vector<string>> findsequence(string bword, string eword, vector<string>& wordlist){
        unordered_set<string> st(wordlist.begin(), wordlist.end());

        queue<vector<string>> q;
        q.push({bword});
        vector<string> usedonlevel;
        usedonlevel.push_back(bword);
        int level=0;
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec=q.front();
            q.pop();

            if(vec.size()>level){
                level++;
                for(auto it: usedonlevel){
                    st.erase(it);
                }
            }
            string word=vec.back();
            if(word==eword){
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);

                }
            }

            for(int i=0; i<word.size();i++){
                char original=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        usedonlevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i]=original;
            }
        }
        return ans;

    }
};

bool comp(vector<string> a, vector<string> b){
    string x="",y="";
    for(string i: a){
        x+=i;
    }
    for(string i:b){
        y+=i;
    }
    return x<y;
}


int main(){
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    solution obj;
    vector<vector<string>> ans = obj.findsequence(startWord, targetWord, wordList);
    
    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}