#include <iostream>
using namespace std;
void bubbleSort(int arr[], int num) {
    for (int i = num-1 ; i > 0 ; i --) {
        for (int j = 0 ; j < i ; j ++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for (int i = 0 ; i < num ; i ++) {
        cout << arr[i] << " ";
    }
}
int main() {
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0 ; i < num ; i++) {
        cin >> arr[i];
    }
    bubbleSort(arr,num);
}