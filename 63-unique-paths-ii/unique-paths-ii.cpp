class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        vector<vector<int>> f(n, vector<int>(m, 0));
        if(a[0][0] == 1) return 0;
        f[0][0] =1;
        for(int i = 1; i < m; i++)
        {
            if(a[0][i] == 1) f[0][i] = 0;
            else f[0][i] = f[0][i - 1];
        }

        for(int i = 1; i < n; i++)
        {
            if(a[i][0] == 1) f[i][0] = 0;
            else f[i][0] = f[i - 1][0];
        }

        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < m; j++)
            {
                if(a[i][j] == 1) f[i][j] = 0;
                else if(a[i][j] == 0)
                {
                    f[i][j] = f[i - 1][j] + f[i][j- 1];
                }
            }
        }

        return f[n - 1][m - 1];
    }
};