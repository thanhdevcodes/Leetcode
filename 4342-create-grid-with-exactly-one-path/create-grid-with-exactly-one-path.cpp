class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> a(m, string(n, '#'));

        for(int i = 0; i < n; i++) a[0][i] = '.';
        for(int i = 0; i < m; i++) a[i][n - 1] = '.';
        return a;
    }
};