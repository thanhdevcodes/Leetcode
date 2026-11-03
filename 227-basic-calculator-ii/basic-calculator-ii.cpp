class Solution {
public:

int check(char c)
{
    if(c == '(') return 0;
    if(c == '+' || c == '-') return 1;
    if(c == '/' || c == '*') return 2;
    return 3;
}

int check1(string c){
    if(c == "+") return 1;
    if(c == "-") return 1;
    if(c == "*") return 1;
    if(c == "/") return 1;
    return 0;
}
    int calculate(string s) {
        stringstream ss(s);
        string word;
        string ans = "";
        while(ss >> word)
        {
            ans += word;
        }
        int n = ans.size();

        stack<char> st;
        vector<string> res;
        for(int i = 0; i <n; i++)
        {
            if(ans[i] == '(') st.push(ans[i]);
            else if(ans[i] == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    res.push_back(string(1, st.top())); st.pop();
                }
                st.pop();
            }
            else if(isdigit(ans[i]))
            {
                string num = "";
                while(i < n && isdigit(ans[i]))
                {
                    num += ans[i];
                    i++;
                }
                res.push_back(num);
                i--;
            }
            else
            {
                while(!st.empty() && check(st.top()) >= check(ans[i]))
                {
                    res.push_back(string(1, st.top())); st.pop();
                }
                st.push(ans[i]);
            }
        }

        while(!st.empty())
        {
            res.push_back(string(1, st.top())); st.pop();
        }

        stack<long long> st1;
        int m = res.size();

        for(int i = 0; i < m; i++)
        {
            string c = res[i];
            if(check1(c))
            {
                long long x = st1.top(); st1.pop();
                long long y = st1.top(); st1.pop();

                long long sum = 0;
                if(c == "+") sum = y + x;
                if(c == "-") sum = y - x;
                if(c == "*") sum = y * x;
                if(c == "/") sum = y / x;
                st1.push(sum);
             }
            else st1.push(stoll(c));
        }

        return st1.top();
    }
};