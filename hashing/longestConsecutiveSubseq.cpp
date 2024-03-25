#include <iostream>
#include <vector>
using namespace std;
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    vector<int>output;
    int maxlength=0;
    int len=0;
    int start;
    int end;
    unordered_map<int,bool>res;
    for(int i=0;i<n;i++){
        res[arr[i]]=true;
    }
    int i=0;
    while(i<n){
        if(res[arr[i]]==true){
        int curr=arr[i];
        int temp=arr[i]-1;
        len=0;
        while(res.count(curr)>0){
            res[curr]=false;
            len++;
            curr++;
        }
        if(curr!=arr[i]){
            curr--;
        }
        while(res.count(temp)>0){
            res[temp]=false;
            len++;
            temp--;
        }

        if(len>maxlength){
                maxlength=len;
                start=temp+1;
                end=curr; 
        }
        if(len==maxlength){
            int q,w;
            for(int i=0;i<n;i++){
                if(arr[i]==start) q=i;
                if(arr[i]==temp+1) w=i;
            }
            if(w<q){
                maxlength=len;
                start=temp+1;
                end=curr; 
            }
        }
        }
        i++;
    }
    if(maxlength==1){
        output.push_back(start);

    } else {
        output.push_back(start);
        output.push_back(end);
    }
    return output;
}
int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
