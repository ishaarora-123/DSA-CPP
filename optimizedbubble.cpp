#include <iostream>
using namespace std;
void bubbleSort(int* arr, int num) {
    for (int i = num-1 ; i > 0 ; i --) {
        int swaps = 0;
        for (int j = 0 ; j < i ; j ++) {
            if (arr[j] > arr[j+1]) {
                swaps ++;
                swap(arr[j], arr[j+1]);
            }
        }
        if (swaps == 0) {
            break;
        }
    }
}
int main() {
    int num;
    cin >> num;
    int *arr = new int[num];
    for (int i = 0 ; i < num ; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr,num);
    for (int i = 0 ; i < num ; i ++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
}