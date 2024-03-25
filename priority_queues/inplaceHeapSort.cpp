#include <iostream>
// #include "solution.h"
void heapSort(int arr[], int n) {
    // build a heap
    if (n == 0 || n == 1) {
        return;
    }

    for (int i = 1; i < n; i++) {
        int current = i;
        while (current>0&&arr[current]<arr[(current-1)/2]) {
            int temp = arr[current];
            arr[current] = arr[(current - 1) / 2];
            arr[(current - 1) / 2] = temp;
            current = (current - 1) / 2;
        }
    }

    while (n > 1) {
        int temp = arr[0];
        arr[0] = arr[n - 1];
        arr[n - 1] = temp;
        n--;

        int i = 0;
        while (2 * i + 1 < n) {
            int minChild = 2 * i + 1;
            if (2 * i + 2 < n && arr[2 * i + 2] < arr[minChild]) {
                minChild = 2 * i + 2;
            }

            if (arr[i] > arr[minChild]) {
                int t = arr[i];
                arr[i] = arr[minChild];
                arr[minChild] = t;
                i = minChild;
            } else {
                break;
            }
        }
    }
}

using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}