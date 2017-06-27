int Solution::braces(string A) {
    stack<char> st;
    int n = A.length();
    for (int i = 0; i < n; i++)
    {
        if (A[i] == '(')
            st.push('(');
        else if (A[i] == ')')
        {
            if (st.top() =='(')
                return 1;
            int cnt = 0;
            while (st.top() != '(')
                st.pop(), cnt++;
            if (cnt == 1)
                return 1;
            st.pop();
        }
        else
            st.push(A[i]);
    }
    return 0;
}
