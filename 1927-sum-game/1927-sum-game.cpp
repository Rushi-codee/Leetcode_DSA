class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int half = n/2;

        int left_sum = 0, left_q = 0;
        int right_sum = 0, right_q = 0;

       for (int i = 0; i < n; ++i) {
            if (i < half) {
                if (num[i] == '?') left_q++;
                else left_sum += num[i] - '0';
            } else {
                if (num[i] == '?') right_q++;
                else right_sum += num[i] - '0';
            }
        }

       return (left_sum * 2 + left_q * 9) != (right_sum * 2 + right_q * 9);

    }
};