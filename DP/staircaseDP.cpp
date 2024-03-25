#include<bits/stdc++.h>
using namespace std;
int stairs(int n,int MOD){
    if(n<=2){
        return n;
    }
    long int*ans=new long int[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=4;
    for(int i=4;i<=n;i++){
        ans[i]=((ans[i-1]%MOD)+(ans[i-2]%MOD)+(ans[i-3]%MOD))%MOD;
    }
    return ans[n];
}
int main()
{
    // take input from the user.
    int n;
    int MOD=1000000007;
    cin >> n;

    while (n > 0) {
        int k;
        cin>>k;
        cout << stairs(k, MOD)<<endl;
        n--;
    }
    return 0;
}