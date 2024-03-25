#include <iostream>
using namespace std;

// #include "solution.h"
#include <unordered_map>

int highestFrequency(int arr[], int n) {
    // Write your code here
    unordered_map<int,int>res;
    for(int i=0;i<n;i++){
        res[arr[i]]++;
    }
    int maxc=res[arr[0]];
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(res[arr[i]]>maxc){
            maxc=res[arr[i]];
            max=arr[i];
        }
    }
    return max;
    
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}