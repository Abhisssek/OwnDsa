#include<iostream>
using namespace std;
void arrprint(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << "   ";
        cout<<" till sorted ";
    }
}
bool isSorted(int arr[], int size) {
    arrprint(arr, size);
    cout<<" "<<size<<endl;
    //base case
    if(size == 0 || size == 1 ){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
        
    else {
        bool remainingPart = isSorted(arr + 1, size - 1 );
        return remainingPart;
    }

}

int main() {

    int arr[6] = {2,4,6,9,11,13};
    int size = 6;

    bool ans = isSorted(arr, size);

    if(ans){
        cout << "Array is sorted " << endl;
    }
    else {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}