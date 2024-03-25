#include <iostream>
using namespace std;

// #include "solution.h"
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
	if(n<=0||m<=0){
		return 0;
	}
	int**output=new int*[n];
	for(int i=0;i<n;i++){
		output[i]=new int[m];
	}
	int maxSquareSize = 0;
	for(int i=0;i<n;i++){
		output[i][0]=(arr[i][0]==0)?1:0;
		maxSquareSize = max(maxSquareSize, output[i][0]); 
	}
	for(int j=1;j<m;j++){
		output[0][j]=(arr[0][j]==0)?1:0;
		maxSquareSize = max(maxSquareSize, output[0][j]); 
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(arr[i][j]==0){
			output[i][j]=min(output[i-1][j],min(output[i-1][j-1],output[i][j-1]))+1;
			maxSquareSize = max(maxSquareSize, output[i][j]);
			}else{
				output[i][j]=0;
			}
		}
	}
	
	return maxSquareSize;
}

int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}