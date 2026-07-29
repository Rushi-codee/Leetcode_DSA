#include<bits/stdc++.h>
using namespace std;

int countstudents(vector<int>&arr,int pages){
    int n = arr.size();
    int student = 1;
    long long pagestudent = 0;
    for(int i =0; i<n; i++){
        if(pagestudent+arr[i]<=pages){
            pagestudent+=arr[i];
        }else{
            student+=1;
            pagestudent = arr[i];
        }

    }
    return student;


}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid = low+(high-low)/2;

        if(countstudents(arr,mid) > m){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}



class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};