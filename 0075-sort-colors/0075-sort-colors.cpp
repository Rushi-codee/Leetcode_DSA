#include<bits/stdc++.h>
class Solution {
public:
    void sortColors(vector<int>& nums) {
       int n = nums.size();
    // Solved using duch national flag algorithm 

/*
Where 

0 To  low-1  is 0
low To mid-1 is1
high+1 To n-1 is 2

we have to sort for mid to high 
*/
       int low =0;
       int mid = 0;
       int high = n-1;

       while(mid<=high){

        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }else if(nums[mid]==1){
            mid++;
        }else{
            swap(nums[mid],nums[high]);
            high--;
        }
       }
    }
};