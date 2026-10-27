class Solution {
public:

int n, m, ans = 0, empty = 1;

void Try(vector<vector<int>>& a, int i, int j, int cnt)
{
    if(i >= n || i < 0 || j >= m || j < 0 || a[i][j] == -1) return;

    if(a[i][j] == 2)
    {
        if(cnt == empty) ans++;
        return;
    }

    a[i][j] = -1;

    Try(a, i + 1, j, cnt + 1);
    Try(a, i - 1, j, cnt + 1);
    Try(a, i, j + 1, cnt + 1);
    Try(a, i, j - 1, cnt + 1);

    a[i][j] = 0;
}

    int uniquePathsIII(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        int x, y;
        ans = 0;
        for(int i = 0; i <n ; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i][j] == 1)
                {
                    x = i, y = j;
                }
                else if(a[i][j] == 0) empty++;
            }
        }

        Try(a, x, y, 0);
        return ans;

    }
};