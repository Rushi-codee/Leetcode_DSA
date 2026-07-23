#include <bits/stdc++.h>
using namespace std;

// Helper function to find the maximum elements in the piles
int findmax(const vector<int> &piles){
    int maxi = INT_MIN;
    int n = piles.size();

    for(int i = 0; i < n; i++){
        if(piles[i] > maxi){
            maxi = piles[i];
        }
    }
    return maxi;
}

// Helper function to calculate total hours required for a given hourly speed
long long calctotalhours(const vector<int> &piles, long long hourly){
    int n = piles.size();
    long long totalhrs = 0;
    for(int i = 0; i < n; i++){
       // Ceiling division logic
       totalhrs += (piles[i] + hourly - 1) / hourly;
    }
    return totalhrs;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = findmax(piles);

        while(low <= high){
            // FIX 1: Use long long for mid to prevent overflow, and avoid double
            long long mid = low + (high - low) / 2; 
            long long totalhrs = calctotalhours(piles, mid);

            if(totalhrs <= h){
               high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
