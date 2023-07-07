#include<bits/stdc++.h>
using namespace std;
// int firstOcc(vector<int>& arr, int n, int key) {

//     int s = 0, e = n-1;
//     int mid = s + (e-s)/2;
//     int ans = -1;
//     while(s<=e) {

//         if(arr[mid] == key){
//             ans = mid;
//             e = mid - 1;
//         }
//         else if(key > arr[mid]) {//Right me jao
//             s = mid + 1;
//         }
//         else if(key < arr[mid]) {//left me jao
//             e = mid - 1;
//         }

//         mid = s + (e-s)/2;
//     }
//     return ans;
// }

// int lastOcc(vector<int>& arr, int n, int key) {

//     int s = 0, e = n-1;
//     int mid = s + (e-s)/2;
//     int ans = -1;
//     while(s<=e) {

//         if(arr[mid] == key){
//             ans = mid;
//             s = mid + 1;
//         }
//         else if(key > arr[mid]) {//Right me jao
//             s = mid + 1;
//         }
//         else if(key < arr[mid]) {//left me jao
//             e = mid - 1;
//         }

//         mid = s + (e-s)/2;
//     }
//     return ans;
// }
int main() {
	// vector<int> arr={1,2,3,3,3,3,3,3,4,5};
    // int n= arr.size();
	// cout<<firstOcc(arr,n,3);
	// cout<<lastOcc(arr,n,3);

    int arr[10]={1,2,3,4,5};
    
    // cout<<arr<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<&arr<<endl;
    // cout<<*arr+1<<endl;
    // cout<<*arr<<endl;
    cout<<arr+1<<endl;
    // cout<<arr<<endl;
    // cout << arr[0]<<endl;



/*
int arr[10] = {23, 122, 41, 67};


    cout <<" address of first memory block is " << arr << endl;
    cout << arr[0] << endl;
    cout <<" address of first memory block is " << &arr[0] << endl;

    cout << "4th " << *arr << endl;
    cout << "5th " << *arr + 1 << endl;
    cout << "6th " << *(arr + 1) << endl;
    cout << "7th " << *(arr) + 1 << endl;
    cout << "8th " << arr[2] << endl;
    cout << "9th " << *(arr+2) << endl;

    int i = 3;
    cout << i[arr] << endl;


   int temp[10] = {1,2};
   cout << sizeof(temp) << endl;
   cout << " 1st " <<  sizeof(*temp) << endl;
   cout << " 2nd " <<  sizeof(&temp) << endl;

   int *ptr = &temp[0];
   cout << sizeof(ptr) << endl ;
   cout << sizeof(*ptr) << endl ;
   cout << sizeof(&ptr) << endl ;



   int a[20] = {1,2,3,5};
   //cout << " ->" << &a[0] << endl;
  // cout << &a << endl;
   //cout << a << endl;

   int *p = &a[0];
   //cout << p << endl;
   //cout << *p << endl;
   cout << "-> " << &p << endl;

    */
   
	return 0;
}
