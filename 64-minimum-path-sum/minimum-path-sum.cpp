class Solution {
public:

int ans = INT_MAX;
int n, m;
void Try(vector<vector<int>> &a, int i, int j, int sum)
{
    if(i >= m || j >= n) return;

    sum += a[i][j];

    if(i == m - 1 && j == n - 1) {ans = min(ans, sum); return;}

    Try(a, i + 1, j, sum);
    Try(a, i, j + 1, sum);
}
    int minPathSum(vector<vector<int>>& a) {
        m = a.size();
        n = a[0].size();
        
        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = a[0][0];

        for(int i = 1; i < n; i++)
        {
            f[0][i] = f[0][i - 1] + a[0][i];
        }

        for(int i = 1; i < m; i++)
        {
            f[i][0] = f[i - 1][0] + a[i][0];
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                f[i][j] = a[i][j] + min(f[i- 1][j], f[i][j - 1]);
            }
        }

        return f[m - 1][n - 1];
    }
};