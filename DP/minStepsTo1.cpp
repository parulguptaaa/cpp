#include <bits/stdc++.h>
using namespace std;
// #include "solution.h"
int countMinStepsToOne(int n)
{
	//Write your code here
	if(n==1){
		return 0;
	}
	// int x,y,z;
  int x = 1 + countMinStepsToOne(n - 1);
  int y = (n % 2 == 0) ? 1 + countMinStepsToOne(n / 2) : INT_MAX;
  int z = (n % 3 == 0) ? 1 + countMinStepsToOne(n / 3) : INT_MAX;
  return min(x, min(y, z)) ;

}
// DYNAMIC PROG
int countStepsToOne(int n)
{
	//Write your code here
	int* ans=new int[n+1];
	ans[0]=0;
	ans[1]=0;
	ans[2]=1;
	ans[3]=1;
	for(int i=4;i<=n;i++){
		int y=INT_MAX,z=INT_MAX;
		if(i%2==0){
			y=1+ans[i/2];
		}
		if(i%3==0){
			z=1+ans[i/3];
		}
		int x=1+ans[i-1];
		ans[i]=min(x,min(y,z));
	}
	return ans[n];
}
// MEMOIZATION
int minSteps_2Helper(int n,int* ans){
    if(n<=1){
        return 0;
    }
    // check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    // calculate output
    int x=minSteps_2Helper(n-1,ans);
    int y=INT_MAX,z=INT_MAX;
    if(y%2==0){
        y=minSteps_2Helper(n/2,ans);
    }
    if(z%3==0){
        z=minSteps_2Helper(n/3,ans);
    }
    int output=min(x,(min(y,z))+1);
    ans[n]=output;
    return output;
}
int minSteps_2(int n){
    int*ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return minSteps_2Helper(n,ans);
}
// BRUTE FORCE RECURSION
int minSteps(int n){
    if(n<=1){
        return 0;
    }
    int x=minSteps(n-1);
    int y=INT_MAX,z=INT_MAX;
    if(n%2==0){
        y=minSteps(n/2);
    }
    if(n%3==0){
        z=minSteps(n/3);
    }
    int ans=min(x,min(y,z))+1;
    return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}