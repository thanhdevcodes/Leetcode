class Solution {
public:
    string longestPalindrome(string s) {
        s = 'x' + s;
        int n = s.size();
        bool f[n + 1][n + 1];
        for(int i = 1; i <= n; i++) f[i][i] = 1;
        int ans = 1;
        int pos = 1;
        for(int len = 2; len <= n; len++)
        {
            for(int i = 1; i <= n - len + 1; i++)
            {
                int j = i + len - 1;
                if(len == 2)
                {
                    if(s[i] != s[j]) f[i][j] = 0;
                    else f[i][j] = 1;
                }
                else
                {
                    f[i][j] = (s[i] == s[j] && f[i + 1][j - 1]);
                }
                if(f[i][j])
                {
                    pos = i;
                    ans = max(ans, len);
                }
            }
        }

        return s.substr(pos, ans);
    }
};