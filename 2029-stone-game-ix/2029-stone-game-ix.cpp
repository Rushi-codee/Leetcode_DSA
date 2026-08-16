class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        
        // Count the stones based on their remainders modulo 3
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        
        // Case 1: The number of '0' remainder stones is even
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        
        // Case 2: The number of '0' remainder stones is odd
        return abs(cnt[1] - cnt[2]) > 2;
    }
};