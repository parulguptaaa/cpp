#include <iostream>
using namespace std;
#include<unordered_map>
int pairSum(int *arr, int n) {
	// Write your code here  
	int count=0;
	unordered_map<int,int>res;
	for(int i=0;i<n;i++){
		int comp=(-arr[i]);
		if(res[comp]!=0){
			count+=res[comp];
		}
		res[arr[i]]++;
	}
	return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}