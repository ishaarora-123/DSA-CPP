#include <iostream>
using namespace std;
void  swap(int*arr, int low, int high) {
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp; 
}
int partition(int*arr, int low, int high) {
    int pivot = arr[high];
        int i = (low-1);
        for (int j = low; j < high ; j ++) {
            if (arr[j] < pivot){
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i+1, high);
        return (i+1);
}
void quickSort(int*arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1 ,high);
    }
}
int main() {
    int num;
    cin >> num;
    int *arr = new int[num];
    for (int i = 0 ; i < num ; i++) {
        cin >> arr[i];
    }
    quickSort(arr,0, num-1);
    for (int i = 0 ; i < num ; i ++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
}