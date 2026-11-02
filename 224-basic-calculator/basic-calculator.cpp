class Solution {
public:

int check(char c)
{
    if(c == '+' || c == '-') return 1;
    return 0;
}

int check1(string c)
{
    if(c == "+") return 1;
    if(c == "-") return 1;
    return 0;
}

    int calculate(string s) {
        stringstream ss(s);
        string word;
        string res = "";
        while(ss >> word)
        {
            res += word;
        }
        vector<string> ans;
        int n = res.size();
        stack<char> st;
        for(int i = 0; i <n; i++)
        {
            if(res[i] == '(') st.push(res[i]);
            else if(res[i] == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    ans.push_back(string(1, st.top())); st.pop();
                }
                st.pop();
            }
            else if(isdigit(res[i]))
            {
                string num = "";
                while(i < n && isdigit(res[i]))
                {
                    num += res[i];
                    i++;
                }
                ans.push_back(num);
                i--;
            }
            else if(res[i] == '-' && (i == 0 || res[i-1] == '(' || res[i-1] == '+' || res[i-1] == '-'))
            {
                ans.push_back("0");
                while(!st.empty() && check(st.top()) >= check(res[i]))
                {
                    ans.push_back(string(1, st.top())); st.pop();
                }
                st.push(res[i]);
            }
            else
            {
                while(!st.empty() && check(st.top()) >= check(res[i]))
                {
                    ans.push_back(string(1, st.top())); st.pop();
                }
                st.push(res[i]);
            }
        }

        while(!st.empty())
        {
            ans.push_back(string(1, st.top())); st.pop();
        }

        stack<long long> st1;
        int m = ans.size();

        for(int i = 0; i <m ; i++)
        {
            string c = ans[i];
            if(check1(c))
            {
                long long x = st1.top(); st1.pop();
                long long y = st1.top(); st1.pop();

                int sum = 0;
                if(c == "+") sum = y + x;
                if(c == "-") sum = y - x;
                st1.push(sum);
            }
            else
            {
                st1.push(stoll(c));
            }
        }

        return st1.top();
    }
};