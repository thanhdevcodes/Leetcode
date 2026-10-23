class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();

        int f[n + 1][m + 1];

        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                if(i== 0 || j == 0)
                {
                    f[i][j] = 0;
                }
                else
                {
                    if(s[i - 1] == t[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
                    else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[n][m] == n;
    }
};