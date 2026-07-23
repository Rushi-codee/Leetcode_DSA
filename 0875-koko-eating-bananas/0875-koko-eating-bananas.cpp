#include<bits/stdc++.h>
int findmax(vector<int> &piles){
    int maxi = INT_MIN;
    int n = piles.size();

    for(int i = 0; i<n; i++){
        if(piles[i]>maxi){
            maxi = piles[i];
        }
    }
    return maxi;
}

long long  calctotalhours(vector<int> &piles,long long  hourly){
    int n = piles.size();
    long long totalhrs = 0;
    for(int i =0; i<n; i++){
      totalhrs += (double(piles[i]) + double(hourly) - 1) / double(hourly);

        
    }
    return totalhrs;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long low = 1;
        long long  high = findmax(piles);

        while(low<=high){
            double mid = (low+high)/2;
            long long  totalhrs = calctotalhours(piles,mid);

            if(totalhrs <= h){
               high = mid-1;
            }else{
                low = mid+1;
            }

        }


        return low;
    }
    
};