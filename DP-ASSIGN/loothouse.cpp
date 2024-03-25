#include <iostream>
using namespace std;

// #include "solution.h"
int maxMoneyLooted(int *arr, int n)
{
	// brute force
	// int x=0,y=0;
	// for(int i=0,j=1;i<n&&j<n;i+2,j+2){
	// 	x+=arr[i];
	// 	y+=arr[j];
	// }
	// return max(x,y);

    // recursive
	// if(n<=0){
	// 	return 0;
	// }
	// return max((arr[0]+maxMoneyLooted(arr+2, n-2)),maxMoneyLooted(arr+1, n-1));

    // DP
	int*dp=new int[n];
	dp[0]=arr[0];
	dp[1]=max(arr[0],arr[1]);
	for(int i=2;i<n;i++){
		dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
	}
	return dp[n-1];
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}