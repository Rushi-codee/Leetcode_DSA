class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            // Initialize current product to 1
            int prod = 1;

            // Inner loop picks the ending index
            for (int j = i; j < nums.size(); j++) {
                // Multiply current number to product
                prod *= nums[j];

                // Update maximum product if needed
                maxProd = max(maxProd, prod);
            }
        }

        // Return the result
        return maxProd;
    }
};