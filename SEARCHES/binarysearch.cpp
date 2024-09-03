#include <iostream>
using namespace std;
int binarySearch(int size, int arr[] , int target) {
    int i = 0;
    while (size>=i) {
        int mid = (size+i)/2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            i = mid+1;
        }
        else {
            size = mid-1;
        }
    }
    return -1;
}
int main() {
    int num;
    int target;
    cout << "Enter the size of the array: ";
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target element: ";
    cin >> target;
    cout << binarySearch(num,arr,target);
}