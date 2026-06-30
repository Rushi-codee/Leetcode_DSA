#include<bits/stdc++.h>
class Solution {
public:
    void nextPermutation(vector<int>& arr) {


        // brute will be 

        /* 1.generate all permuttaions in sorted order
        2. linear serch 
        3. next permutation */
        

        // This is better approch 
        // next_permutation(nums.begin(),nums.end());


        // Best Optimal approch

        int n = arr.size();
        int idx = -1;

        for(int i = n-2; i>=0 ;i--){
            if(arr[i]<arr[i+1]){
                idx = i;
                break;
            }
            
        }
        if(idx == -1){
                reverse(arr.begin(),arr.end());
                 return;
            }
        for(int i = n-1; i>=idx ;i--){
            if(arr[i]>arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        reverse(arr.begin() + idx + 1,arr.end());

        
    }
};