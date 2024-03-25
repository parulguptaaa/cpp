#include <bits/stdc++.h>
using namespace std;
// Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
// That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. 
// The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares
// #include "solution.h"
int minCount(int n)
{
	//Write your code here
	if(n<=2){
		return n;
	}
	int *count=new int[n+1];
	count[0]=0;
	count[1]=1;
	count[2]=2;
	count[3]=3;
	
	for(int i=4;i<=n;i++){
		int min=INT_MAX;
	for(int k=1;k<=(i/k);k++){
		count[i]=count[n-(k*k)]+1;
			int newmin=count[i];

                if (newmin < min) {
                  min = newmin;
                  count[i] = min;
                }
        }
        }
        return count[n];
}

int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}