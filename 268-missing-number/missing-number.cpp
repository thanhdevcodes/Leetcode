class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long long s = n*(n + 1)/2;

        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        return s - sum;
    }
};