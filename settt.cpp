#include<bits/stdc++.h>

using namespace std;

int main() {
  set < int > s;
  for (int i = 1; i <= 10; i++) {
    s.insert(i);
  }
  //printing all the elements of the set
  for (auto it = s.begin(); it!= s.end(); it++) {
    cout << *it << " ";
  
}
cout << endl;
//finding a element in the set
int n = 2;
  if (s.find(2) != s.end())
    cout << n << " is present in set" << endl;
  //erasing 1st element from the set
  s.erase(s.begin());
  cout << "Elements after deleting the first element: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;
  // size of the set
  cout << "The size of the set is: " << s.size() << endl;
  //checking if the set is empty
  if (s.empty() == false)
    cout << "The set is not empty " << endl;
  else
    cout << "The set is empty" << endl;
  s.clear();
  cout << "Size of the set after clearing all the elements: " << s.size();

}