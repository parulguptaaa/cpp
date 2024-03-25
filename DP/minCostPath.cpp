#include <bits/stdc++.h>
using namespace std;

// #include "solution.h"
#include<climits>
#include <algorithm>
int helper(int** input,int m,int n,int i,int j){
	// base case
	// int*a=input[i,j];
	if(i==m-1&&j==n-1){
		return input[i][j];
	}
	if(i>=m||j>=n){
		return INT_MAX;
	}
	// reursive call
	int x=helper(input, m, n, i+1, j);
	int y=helper(input, m, n, i, j+1);
	int z=helper(input, m, n, i+1, j+1);
	
	return min(min(x,y),z)+input[i][j];
}
// using memoization
int helperm(int** input,int m,int n,int i,int j,int** output){
	// base case
	// int*a=input[i,j];
	if(i==m-1&&j==n-1){
		return input[i][j];
	}
	if(i>=m||j>=n){
		return INT_MAX;
	}
	if(output[i][j]!=-1){
		return output[i][j];
	}
	// reursive call
	int x=helperm(input, m, n, i+1, j,output);
	int y=helperm(input, m, n, i, j+1,output);
	int z=helperm(input, m, n, i+1, j+1,output);
	
	int a=min(min(x,y),z)+input[i][j];
	output[i][j]=a;
	return a;
}
// DP
int minCostPath_DP(int**input,int m,int n){
	int**output=new int*[m];
	for(int i=0;i<m;i++){
		output[i]=new int[n];
	}
	// fill the destination cell
	output[m-1][n-1]=input[m-1][n-1];
	// fill last row right->left
	for(int j=n-2;j>=0;j--){
		output[m-1][j]=input[m-1][j]+output[m-1][j+1];
	}
	// fill last column bottom->top
	for(int i=m-2;i>=0;i--){
		output[i][n-1]=input[i][n-1]+output[i+1][n-1];
	}
	// remaining cells
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			output[i][j]=min(min(output[i+1][j],output[i][j+1]),output[i+1][j+1])+input[i][j];
		}
	}
	return output[0][0];
}
int minCostPath(int **input, int m, int n)
{
	int**output=new int*[m];
	for (int i = 0; i < m; i++)
	{
		output[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{ 
			output[i][j]=-1;
		}
	}
	return helperm(input, m, n, 0, 0,output);
	// return helper(input, m, n, 0, 0);

}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
	cout << minCostPath_DP(arr, n, m) << endl;

}