int Solution::evalRPN(vector<string> &A) {
    int n = A.size();
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        if (A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")
        {
            int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            int v3;
            if (A[i] == "+")
                v3 = v1 + v2;
            else if (A[i] == "*")
                v3 = v1 * v2;
            else if (A[i] == "-")
                v3 = v2 - v1;
            else if (A[i] == "/")
                v3 = v2 / v1;
            st.push(v3);
            continue;
        }
        int neg = 0;
        for (int j = 0; j < A[i].length(); j++)
        {
            if (A[i][j] == '-')
            {
                neg = 1;
                continue;
            }
            int x = A[i][j] - '0';
            val *= 10;
            val += x;
        }
        if (neg)
            val *= -1;
        st.push(val);
    }
    return st.top();
}
