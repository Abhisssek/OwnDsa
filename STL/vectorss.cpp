#include<bits/stdc++.h>
using namespace std;

int main(){
    // Initialize vector
    vector<int>v;
    // adding values to vector
    int i=1;
    while (i<=10)
    {
     v.push_back(i);
     i++;
    }
    // printing values of vector
    
    // inserting extra element
    v.insert(v.begin(), 5);

    //erase 1st elements
    v.erase(v.begin());
    //deleting last element
    v.pop_back();
    //  reference of the 1st element
    cout<<v.front();
    //reference of the last element
    cout<<v.back();
    //clearing all elements
    v.clear();
    cout << v.size() << endl;
    // check if the vector is empty
    if (v.empty())
    {
        cout << "Vector is empty" << endl;
    }
    else
    {
        cout << "Vector is not empty" << endl;
    }
    return 0;



    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }

    return 0;
}