int solve(int n, vector<int> &dp, const vector<int> &A)
{
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] < A[n])
            dp[n] = max(dp[n], 1 + solve(i, dp, A));
    }
    return dp[n];
}

int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, solve(i, dp, A));
    return ans;
}

