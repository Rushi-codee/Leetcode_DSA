class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixGcd;
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++)
        {
                if(nums[i]>maxi)
                {
                    maxi = nums[i];
                }
                prefixGcd.push_back(gcd(nums[i],maxi));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int n=prefixGcd.size();
        int j=n-1;
        long long sum=0;
        for(int i=0;i<n/2;i++)
        {
            if(j>=n/2 ){
                sum+=gcd(prefixGcd[i],prefixGcd[j]);
                j--;
            }
        }
        return sum;
    }
};