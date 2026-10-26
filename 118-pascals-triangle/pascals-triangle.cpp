class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> a(n, vector<int>(n));
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0 || j == i)
                {
                    a[i][j] = 1;
                }
                else
                {
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                }
            }
        }

        for(int i= 0; i < n; i++)
        {
            vector<int> row;
            for(int j = 0; j <= i; j++)
            {
                row.push_back(a[i][j]);
            }
            ans.push_back(row);
        }

        return ans;
    }
};