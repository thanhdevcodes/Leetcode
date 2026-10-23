class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>> ans;
        sort(a.begin(), a.end());

        do
        {
            ans.push_back(a);
        }while(next_permutation(a.begin(), a.end()));
        return ans;
    }
};