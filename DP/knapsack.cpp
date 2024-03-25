#include <iostream>
using namespace std;

// #include "solution.h"
// bruteforce
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
	if(n==0||maxWeight==0){
		return 0;
	}
	if(weights[0]>maxWeight){
		return knapsack(weights+1, values+1, n-1, maxWeight);
	}
	int x=knapsack(weights+1, values+1, n-1, maxWeight-weights[0])+values[0];
	int y=knapsack(weights+1, values+1, n-1, maxWeight);
	return max(x,y);
}
// DP
int knapsack_DP(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
	int**arr=new int*[n+1];
	for(int i=0;i<n+1;i++){
		arr[i]=new int[maxWeight+1];
	}
	// first col
	for(int i=0;i<n+1;i++){
		arr[i][0]=0;
	}
	// first row
	for(int w=1;w<maxWeight+1;w++){
		arr[0][w]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int w=1;w<maxWeight+1;w++){
			if(weight[i-1]>w){
				arr[i][w]=arr[i-1][w];
			}else{
				arr[i][w]=max((value[i-1]+arr[i-1][w-weight[i-1]]),arr[i-1][w]);
			}
		}
	}
	return arr[n][maxWeight];
}
int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}