#include <cstring>
#include <iostream>
using namespace std;

// #include "solution.h"
// bruteforce
int editDistance(string s1, string s2) {
	// Write your code here
	if(s2.size()==0||s1.size()==0){
		return max(s1.size(),s2.size());
	}
	if(s1[0]==s2[0]){
		return editDistance(s1.substr(1), s2.substr(1));
	}else{
		int insert=1+editDistance(s1.substr(1), s2);
		int del=1+editDistance(s1, s2.substr(1));
		int update=1+editDistance(s1.substr(1), s2.substr(1));
		return min(min(insert,del),update);
	}
}
// memoization
int editDistance_mem(string s1, string s2,int**output){
	int m=s1.size();
	int n=s2.size();
	if(m==0||n==0){
		return max(m,n);
	}
	if(output[m][n]!=-1){
		return output[m][n];
	}
	int ans;
	if(s1[0]==s2[0]){
		ans=editDistance_mem(s1.substr(1), s2.substr(1),output);
	}else{
		int insert=1+editDistance_mem(s1.substr(1), s2,output);
		int del=1+editDistance_mem(s1, s2.substr(1),output);
		int update=1+editDistance_mem(s1.substr(1), s2.substr(1),output);
		ans=min(min(insert,del),update);
	}
	output[m][n]=ans;
	return ans;
}
// DP
int editDistance_DP(string s1, string s2, int **output) {
	int m=s1.size();
	int n=s2.size();
	// first col
	for(int i=0;i<m+1;i++){
		output[i][0]=i;
	}
	for(int j=0;j<n+1;j++){
		output[0][j]=j;
	}
	for(int i=1;i<m+1;i++){
		for(int j=1;j<n+1;j++){
			if(s1[m-i]==s2[n-j]){
				output[i][j]=output[i-1][j-1];
			}else{
				output[i][j]=1+min(min(output[i-1][j],output[i][j-1]),output[i-1][j-1]);
			}
		}
	}
	return output[m][n];
}
int editDistance_initialFunc(string s1, string s2)
{
	//Write your code here
	int m=s1.size();
	int n=s2.size();
	int**output=new int*[m+1];
	for(int i=0;i<m+1;i++){
		output[i]=new int[n+1];
	}
	for(int i=0;i<m+1;i++){
		for(int j=0;j<n+1;j++){
			output[i][j]=-1;
		}
	}
	return editDistance_DP(s1,s2,output);
}
int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2)<<endl;
    cout<<editDistance_initialFunc(s1,s2)<<endl;
}