#include <iostream>
using namespace std;

// #include "solution.h"
#include<cmath>
int balancedBTs(int n) {
    // Write your code here
    if (n<=1){
        return 1;
    }
    int x=balancedBTs(n-1);
    int y=balancedBTs(n-2);
    int mod=(int)(pow(10,9)+7);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    int ans=(int)((temp1+temp2)%mod);
    return ans;

}
// DP approach
int balancedBTs(int n) {
    // Write your code here
    int mod=(int)(pow(10,9)+7);
    int *arr=new int[n+1];
    arr[0]=1;
    arr[1]=1;
    arr[2]=3;
    for(int i=3;i<=n;i++){
        int temp1=(int)(((long)(arr[i-1])*arr[i-1])%mod);
        int temp2=(int)((2*(long)(arr[i-1])*arr[i-2])%mod);
        arr[i]=(int)((temp1+temp2)%mod);
    }
    return arr[n];
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}