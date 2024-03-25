#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
using namespace std;
#include<unordered_map>
bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    if(sizeof(input1)!=sizeof(input2)){
        return false;
    }
    unordered_map<char,int>res;
    for(int i=0;i<sizeof(input1);i++){
        res[input1[i]]++;
    }
    for(int i=0;i<sizeof(input2);i++){
        res[input2[i]]--;
    }
    for(int i=0;i<sizeof(input1);i++){
        if(res[input1[i]]!=0){
            return false;
        }
    }
    return true;
}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}