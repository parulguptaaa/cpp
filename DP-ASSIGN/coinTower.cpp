#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"
string findWinner(int n, int x, int y)
{
	// Write your code here .
	bool* dp=new bool[n+1];
	dp[0]=false;
	dp[1]=true;

	for(int i=2;i<n+1;i++){
		if(i-1>=0&&!dp[i-1]){
			dp[i]=true;
		}else if(i-y>=0&&!dp[i-y]){
			dp[i]=true;
		}else if(i-x>=0&&!dp[i-x]){
			dp[i]=true;
		}else{
			dp[i]=false;
		}
	}
	if(dp[n]){
		return "Beerus";
	}else{
		return "Whis";
	}
}


int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	cout << findWinner(n, x, y);
}