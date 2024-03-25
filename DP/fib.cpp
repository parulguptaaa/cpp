#include<iostream>
using namespace std;

// T(n)=O(2^n)
int fibo_1(int n){
    if(n<=1){
        return n;
    }
    int a=fibo_1(n-1);
    int b=fibo_1(n-2);
    return a+b;
}
// Memoization(top-down approach)
int fibo_helper(int n,int*ans){
    if(n<=1){
        return n;
    }
    // check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    int a=fibo_helper(n-1,ans);  
    int b=fibo_helper(n-2,ans);
    // save the output for future use
    ans[n]=a+b;
    // return final output
    return ans[n];
}
// T(n)=O(n)
int fibo_2(int n){
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}
// DYNAMIC PROGRAMING(bottom up approach)
// T(n)=O(n)
int fibo_3(int n){
    int*ans=new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2];
    }
    return ans[n];
}
int main(){
    int n;
    cout<<"enter n: "<<endl;
    cin>>n;
    cout<<"nth fibonacci number is: "<<fibo_2(n);
    return 0;
}