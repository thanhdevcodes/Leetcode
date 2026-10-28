class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<bitset<1024>> dp(m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0) {
                    dp[j].set(grid[i][j]);
                    continue;
                }

                bitset<1024> cur;

                for (int x = 0; x < 1024; x++) {
                    if (i > 0 && dp[j].test(x)) {
                        cur.set(x ^ grid[i][j]);
                    }

                    if (j > 0 && dp[j - 1].test(x)) {
                        cur.set(x ^ grid[i][j]);
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[m - 1].test(x)) {
                return x;
            }
        }

        return 0;
    }
};