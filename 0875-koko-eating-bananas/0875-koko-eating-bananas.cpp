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
const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}
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