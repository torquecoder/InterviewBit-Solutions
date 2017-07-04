int inc(int n, vector<int> &dp1, const vector<int> &A)
{
    if (n == 0)
        return 1;
    if (dp1[n] != -1)
        return dp1[n];
    dp1[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] < A[n])
            dp1[n] = max(dp1[n], 1 + inc(i, dp1, A));
    }
    return dp1[n];
}

int dec(int n, vector<int> &dp2, const vector<int> &A)
{
    if (n == A.size() - 1)
        return 1;
    if (dp2[n] != -1)
        return dp2[n];
    dp2[n] = 1;
    for (int i = n + 1; i < A.size(); i++)
    {
        if (A[i] < A[n])
            dp2[n] = max(dp2[n], 1 + dec(i, dp2, A));
    }
    return dp2[n];
}


int Solution::longestSubsequenceLength(const vector<int> &A) {
    int n = A.size();
    if (n == 1)
        return 1;
    vector<int> dp1, dp2;
    dp1.resize(n, -1);
    dp2.resize(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                ans = max(ans, inc(i, dp1, A) + dec(j, dp2, A) - 1);
            else if (A[j] < A[i])
                ans = max(ans, inc(i, dp1, A) + dec(j, dp2, A));
        }
    }
    return ans;
}

