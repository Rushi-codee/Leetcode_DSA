#include<bits/stdc++.h>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int n2 = nums2.size();

        vector<int> arr;
        arr.reserve(n + n2);

        int i =0; int j =0;
        while (i < n && j < n2) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
         while (i < n) {
            arr.push_back(nums1[i++]);
        }

        while (j < n2) {
            arr.push_back(nums2[j++]);
        }

        int totalSize = arr.size();
        if (totalSize % 2 == 1) {
           
            return arr[totalSize / 2];
        } else {
           
            return (arr[(totalSize / 2) - 1] + arr[totalSize / 2]) / 2.0;
        }
    }
};