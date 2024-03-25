#include <iostream>
using namespace std;

// #include "solution.h"
#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    if(n==0){
        return 0;
    }
    unordered_map<int,int>res;
    int a=0;
    int len=0;
    int maxlen=0;
    for(int i=0;i<n;i++){
        a+=arr[i];
        if(a==0)maxlen=i+1;
        if(res.count(a)>0){
            len=i-res[a];
            if(len>maxlen){
                maxlen=len;
            }
        } else {
          res[a] = i;
        }
    }
    return maxlen;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}