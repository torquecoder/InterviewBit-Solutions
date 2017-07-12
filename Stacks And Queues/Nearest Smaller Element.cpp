vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> ans;
    if (A.size() == 0)
        return ans;
    for (int i = 0; i < A.size(); i++)
    {
        if (st.empty())
        {
            st.push(A[i]);
            ans.push_back(-1);
        }
        else if (st.top() < A[i])
        {
            ans.push_back(st.top());
            st.push(A[i]);
        }
        else
        {
            while (!st.empty() && st.top() >= A[i])
                st.pop();
            if (st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(A[i]);
        }
    }
    return ans;
}

