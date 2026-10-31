class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        vector<string> a;
        int n = 0;
        while(ss >> word)
        {
            a.push_back(word);
        }

        return a.back().size();
    }
};