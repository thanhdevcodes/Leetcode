class Solution {
public:
    int findMinimumOperations(string a, string b, string c) {
        int n = a.size(), m = b.size(), z = c.size();
        if(a[0] != b[0] || b[0] != c[0] || a[0] != c[0]) return -1;
        int i;
        for(i = 0; i < min({n, m, z}); i++)
        {
            if(a[i] != b[i] || b[i] != c[i]) break;
        }
        return n + m + z - 3*i;
    }
};