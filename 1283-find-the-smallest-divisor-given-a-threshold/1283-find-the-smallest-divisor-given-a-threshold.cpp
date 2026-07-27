#include<bits/stdc++.h>
// function that calculate sum  to check with threshold
int findsum(vector<int> &nums, int divisor){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum + ceil((double)(nums[i])/(double)(divisor));
    }
    return sum;
}
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low<=high){
            int mid = low +(high-low)/2;
            if(findsum(nums,mid)<= threshold){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }

       return low;
    }
};