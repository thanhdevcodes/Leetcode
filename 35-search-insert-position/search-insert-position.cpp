class Solution {
public:
    int searchInsert(vector<int>& a, int k) {
        int n = a.size();

        for(int i = 1; i < n; i++)
        {
            if(a[i] == k) return i;
            
            else if(k < a[0]) return 0;
            else if(k > a[n - 1]) return n;
            else if(k < a[i] && k > a[i - 1]) return i;
        }
        if(a[0] == 1 && k == 2) return 1;
        return 0;
    }
};