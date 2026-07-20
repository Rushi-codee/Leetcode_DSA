#include<bits/stdc++.h>
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int  n = nums.size();
        if(n==1) return 0;  // if the array contain only one elemnt that element itself is the the peak so returning its index
        if(nums[0]>nums[1]) return 0;  //edge case 1 if first element is peak i.e -infinity <f irstelement > second element
        if(nums[n-1]>nums[n-2]) return  n-1; //edge case 2 if last element is peak i.e -infinity < n-1 > n-2

        int low = 1;
        int high = n-2;

        while(low<=high){
            int mid = low +(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
            return mid;  // if mid itself is peak element

            }else if(nums[mid]>nums[mid-1]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return -1;

        
    }
};