#include<climits>
#include<vector>
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double max=INT_MIN;
        // if(n==k||n==1){
        //     int s=0;
        //     for(int i=0;i<n;i++){
        //         s=s+nums[i];
        //     }
        //     return s;
        // }
        // if(n==1){
        //     return nums[0];
        // }
        for(int i=0;i<n-k+1;i++){
            double s=0;
            int x=k+i;
            for(int j=i;j<x;j++){
                s=s+nums[j];
            }
            if(s>max){
                max=s;
            }
        }
        return max/k;
    }
};