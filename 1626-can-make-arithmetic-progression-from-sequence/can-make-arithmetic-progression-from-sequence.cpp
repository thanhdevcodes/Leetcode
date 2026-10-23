class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        int x = a[1] - a[0];
        for(int i = 1; i < n - 1; i++)
        {
            if(a[i + 1] - a[i] != x) return false;
        }
        return true;
    }
};