class Solution {
public:
    int triangularSum(vector<int>& a) {
        int n = a.size();
    int b[n][n];
    for(int i = 0; i < n; i++) {b[0][i] = a[i];}

    for(int i = 1; i <n;  i++)
    {
        for(int j = i; j < n; j++)
        {
            b[i][j] = (b[i - 1][j] + b[i - 1][j - 1]) % 10;
        }
    }

    return b[n - 1][n - 1];
    }
};