#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>& arr, int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] > arr[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    return start;
}

int binarySearch(vector<int>& arr, int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int findPosition(vector<int>& arr, int n, int k) {
    int pivot = getPivot(arr, n);

    if (k >= arr[pivot] && k <= arr[n - 1]) {
        return binarySearch(arr, pivot, n - 1, k);
    } else {
        return binarySearch(arr, 0, pivot - 1, k);
    }
}

int main() {
    vector<int> arr = {7, 8, 9, 3, 1};
    cout << findPosition(arr, arr.size(), 4) << endl;

    return 0;
}
//code is not complete yet and might be wrong also./...