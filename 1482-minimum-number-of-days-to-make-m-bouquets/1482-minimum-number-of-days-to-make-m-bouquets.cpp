bool possible(vector<int> & bloomDay, int day, int m , int k){
    int cnt =0;
    int n = bloomDay.size();
    int noOfbo = 0;
    for(int i =0; i<n; i++){
        if(bloomDay[i]<= day){
            cnt++;
        }else{
            noOfbo += (cnt/k);
            cnt = 0;
        }
        
    } 
    noOfbo += (cnt/k);
    return noOfbo >= m;
}



class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m*1LL*k*1LL;
        int n = bloomDay.size();

        if(val>n) return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i<n; i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = low+(high -low) /2;
            if(possible(bloomDay,mid,m,k)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
    
};