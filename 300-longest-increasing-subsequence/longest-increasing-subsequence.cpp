class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int f[n + 1];
        for(int i = 0; i <n; i++) f[i] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j]) f[i] = max(f[i], f[j] + 1);
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, f[i]);
        }
        return ans;
    }
};