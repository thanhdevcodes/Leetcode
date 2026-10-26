class Solution {
public:
    vector<int> getRow(int index) {
        int n = index + 1;
            vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> ans;
 //   memset(a, 0, sizeof(a));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || i == j)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }
    }
    vector<int> row;
    for(int i = 0; i < n; i++)
    {
        row.push_back(a[index][i]);
    }
    return row;
    }
};