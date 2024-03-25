#include <iostream>
using namespace std;

// #include "solution.h"
#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
	int count=0;
	unordered_map<int,int>res;
	for(int i=0;i<n;i++){
		int i1=k+arr[i];
		int i2=arr[i]-k;
		if(res[i1]!=0){
			count+=res[i1];
		}
		if(res[i2]!=0&&i1!=i2){
			count+=res[i2];
		}
		res[arr[i]]++;
	}
	return count;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}