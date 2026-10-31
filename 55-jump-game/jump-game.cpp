class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > ans) return false;
            ans = max(ans, a[i] + i);
        }

        return true;
    }
};