class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f[n];

        f[0] = nums[0];
        if(n >= 2) f[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++)
        {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }
        return f[n-1];
    }
};