class Solution {
public:

int check(string s)
{
    if(s == "+") return 1;
    if(s == "-") return 1;
    if(s == "*") return 1;
    if(s == "/") return 1;
    return 0;
}

    int evalRPN(vector<string>& a) {
        int n = a.size();
        stack<int> st;

        for(int i = 0; i <n ; i++)
        {
            string c = a[i];
            if(check(c))
            {
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();

                int res = 0;
                if(c == "+") res = y + x;
                if(c == "/") res = y / x;
                if(c == "*") res = y * x;
                if(c == "-") res = y - x;
                st.push(res);
            }
            else st.push(stoi(c));
        }
        return st.top();
    }
};