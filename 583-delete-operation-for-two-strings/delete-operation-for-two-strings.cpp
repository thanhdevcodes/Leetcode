class Solution {
public:
    int minDistance(string a, string b) {
        a = 'x' + a, b = 'x' + b;
        
        int n = a.size(), m = b.size();
        
        int f[n + 1][m + 1];
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i == 0 || j == 0)
                {
                    f[i][j] = 0;
                }
                else
                {
                    if(a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
                    else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }

        return n + m - 2*(f[n][m] - 1) - 2;
    }
};