#include <iostream>
#include <string>
using namespace std;

// #include "solution.h"
// Recursion
int solve(string s, string v) {
    // Write your code here
    if (s.empty()) return v.length();
    if (v.empty()) return s.length();
    int j=-1;
    for(int i=0;i<v.length();i++){
        if(s[0]==v[i]){
            j=i;
            break;
        }
    }
    if(j==-1){
        return s.length();
    }
    return min(solve(s.substr(1), v),1+solve(s.substr(1),v.substr(j+1)));
}
// Memoization
int solveH(string s, string v, int**arr){
    int ans;
    if (s.empty()) return v.length();
    if (v.empty()) return s.length();
    if(arr[s.length()][v.length()]!=-1){
        return arr[s.length()][v.length()];
    }
    int j=-1;
    for(int i=0;i<v.length();i++){
        if(s[0]==v[i]){
            j=i;
            break;
        }
    }
    if(j==-1){
        ans= s.length();
        arr[s.length()][v.length()]=ans;
        return ans;
    }
    ans= min(solveH(s.substr(1), v,arr),1+solveH(s.substr(1),v.substr(j+1),arr));
    arr[s.length()][v.length()]=ans;
    return ans;
}
int solve(string s, string v) {
    // Write your code here
    int**arr=new int*[s.length()+1];
    for(int i=0;i<=s.length();i++){
        arr[i] = new int[v.length()+1];
    }
    for(int i=0;i<=s.length();i++){
        for (int j = 0; j <=v.length(); j++) {
          arr[i][j] = -1;
        }
    }
    return solveH(s,v,arr);
}
// DP


int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}