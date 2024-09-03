#include <iostream>
using namespace std;
int binarySearch(int start, int end, int arr[] ,int  target) {
    if(start <= end){
        int mid = (start +end)/2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            return binarySearch(mid+1, end,arr, target);
        }
        if (arr[mid] > target) {
            return binarySearch(start, mid-1,arr, target);
        }
    }
    return -1;
}
int main() {
    int end;
    int target;
    int start = 0;
    cout << "Enter the size of the array: ";
    cin >> end;
    int arr[end];
    for (int i = 0; i < end; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target";
    cin >> target;
    cout << binarySearch(start, end, arr, target);
}