#include<iostream>
using namespace std;
// brute force recursion
int lcs(string s, string t){
    // base case
    if(s.size()==0||t.size()==0){
        return 0;
    }
    if(s[0]==t[0]){
        return 1+lcs(s.substr(1),t.substr(1));
    }else{
        int a=lcs(s.substr(1),t);
        int b=lcs(s,t.substr(1));
        int c=lcs(s.substr(1),t.substr(1));
        return max(max(a,b),c);
    }
}
// memoization
int lcs_mem(string s,string t,int**output){
    int m=s.size();
    int n=t.size();
    if(m==0||n==0){
        return 0;
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    int ans;
    if(s[0]==t[0]){
        ans=1+lcs_mem(s.substr(1),t.substr(1),output);
    }else{
        int a=lcs_mem(s.substr(1),t,output);
        int b=lcs_mem(s,t.substr(1),output);
        int c=lcs_mem(s.substr(1),t.substr(1),output);
        ans= max(max(a,b),c);
    }
    output[m][n]=ans;
    return ans;
}
// dp
int lcs_dp(string s,string t,int**output){
    int m=s.size();
    int n=t.size();
    // first row
    for(int j=0;j<n+1;j++){
        output[0][j]=0;
    }
    // first col
    for(int i=1;i<m+1;i++){
        output[i][0]=0;
    }
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(s[m-i]==t[n-j]){
                output[i][j]=output[i-1][j-1]+1;
            }else{
                int a=output[i-1][j];
                int b=output[i][j-1];
                int c=output[i-1][j-1];
                output[i][j]=max(max(a,b),c);
            }
        }
    }
    return output[m][n];
}
int main(){
    string s,t;
    cin>>s>>t;
    int m=s.size();
    int n=t.size();
    int**output=new int*[m+1];
    for(int i=0;i<m+1;i++){
        output[i]=new int[n+1];
    }
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            output[i][j]=-1;
        }
    }
    cout<<lcs_dp(s,t,output)<<endl;
    cout<<lcs_mem(s,t,output)<<endl;
    cout<<lcs(s,t)<<endl;
}