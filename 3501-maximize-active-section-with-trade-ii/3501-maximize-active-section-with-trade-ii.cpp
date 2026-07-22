class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {



        int n = s.length();
        struct Block { int start, end, len; };
        vector<Block> blocks;
        
        // Step 1: Extract all contiguous 0-blocks
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;
                while (j < n && s[j] == '0') j++;
                blocks.push_back({i, j - 1, j - i});
                i = j;
            } else {
                i++;
            }
        }

        int num_blocks = blocks.size();
        int base_ones = 0;
        for (char c : s) if (c == '1') base_ones++;

        vector<int> ans;
        if (num_blocks < 2) {
            for (auto& q : queries) ans.push_back(base_ones);
            return ans;
        }

        // Step 2: Precalculate adjacent pair gains
        int num_pairs = num_blocks - 1;
        vector<int> pair_gains(num_pairs);
        for (int i = 0; i < num_pairs; ++i) {
            pair_gains[i] = blocks[i].len + blocks[i + 1].len;
        }

        // Step 3: Build a Sparse Table for O(1) Range Maximum Queries (RMQ)
        int max_log = log2(num_pairs) + 1;
        vector<vector<int>> st(num_pairs, vector<int>(max_log));
        for (int i = 0; i < num_pairs; ++i) {
            st[i][0] = pair_gains[i];
        }
        for (int j = 1; j < max_log; ++j) {
            for (int i = 0; i + (1 << j) <= num_pairs; ++i) {
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto query_st = [&](int L, int R) {
            if (L > R) return 0;
            int j = log2(R - L + 1);
            return max(st[L][j], st[R - (1 << j) + 1][j]);
        };

        // Step 4: Efficiently process independent queries in O(1) after Binary Search
        for (const auto& q : queries) {
            int ql = q[0], qr = q[1];
            int max_gain = 0;

            // Binary search to find the range of blocks intersecting [ql, qr]
            int first_intersect = -1, last_intersect = -1;
            
            int low = 0, high = num_blocks - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (blocks[mid].end >= ql) {
                    first_intersect = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            low = 0, high = num_blocks - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (blocks[mid].start <= qr) {
                    last_intersect = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // A valid trade requires at least TWO distinct intersecting blocks
            if (first_intersect != -1 && last_intersect != -1 && first_intersect < last_intersect) {
                
                // 1. Manually check the boundary pairs which could be partially clipped
                // Check the leftmost boundary pair
                int len_first = min(blocks[first_intersect].end, qr) - max(blocks[first_intersect].start, ql) + 1;
                int len_next = min(blocks[first_intersect + 1].end, qr) - max(blocks[first_intersect + 1].start, ql) + 1;
                max_gain = max(max_gain, len_first + len_next);

                // Check the rightmost boundary pair (if distinct from the leftmost pair)
                if (first_intersect + 1 < last_intersect) {
                    int len_last = min(blocks[last_intersect].end, qr) - max(blocks[last_intersect].start, ql) + 1;
                    int len_prev = min(blocks[last_intersect - 1].end, qr) - max(blocks[last_intersect - 1].start, ql) + 1;
                    max_gain = max(max_gain, len_prev + len_last);
                }

                // 2. Use Sparse Table for all fully internal pairs that are untouched by ql and qr boundaries
                // These pairs sit strictly between first_intersect + 1 and last_intersect - 1
                int internal_L = first_intersect + 1;
                int internal_R = last_intersect - 2; 
                if (internal_L <= internal_R) {
                    max_gain = max(max_gain, query_st(internal_L, internal_R));
                }
            }

            ans.push_back(base_ones + max_gain);
        }

        return ans;

    }

        
    
};