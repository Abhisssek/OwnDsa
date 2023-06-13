#include<bits/stdc++.h>

using namespace std;

int main() {

//inserting elements in a map

  map < int, int > mp;
  for (int i = 1; i <= 5; i++) {
    mp.insert({i , i * 10});
  }
//printing the elements in the map
  cout << "Elements present in the map: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;
  }
//finding the element in the map
  int n = 2;
  if (mp.find(2) != mp.end())
    cout << n << " is present in map" << endl;
//erasing the element in the map
  mp.erase(mp.begin());
  cout << "Elements after deleting the first element: " << endl;
  cout << "Key\tElement" << endl;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it -> first << "\t" << it -> second << endl;
  }
//finding the size element in the map
  cout << "The size of the map is: " << mp.size() << endl;
//checking if the map is empty
  if (mp.empty() == false)
    cout << "The map is not empty " << endl;
  else
    cout << "The map is empty" << endl;
  mp.clear();
  cout << "Size of the map after clearing all the elements: " << mp.size();
}