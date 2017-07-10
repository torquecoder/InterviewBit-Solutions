int palin(int l, int r, vector<vector<int> > &pdp, string &A)
{
    if (l == r)
        return 1;
    if (r == l + 1)
    {
        if (A[r] == A[l])
            return 1;
        return 0;
    }
    if (pdp[l][r] != -1)
        return pdp[l][r];
    if (A[l] == A[r])
        pdp[l][r] = palin(l + 1, r - 1, pdp, A);
    else
        pdp[l][r] = 0;
    return pdp[l][r];
}

int solve(int n, vector<int> &dp, string &A, vector<vector<int> > &pdp)
{
    if (n <= 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = INT_MAX;
    if (palin(0, n, pdp, A))
        return dp[n] = 0;
    for (int i = n; i >= 0; i--)
    {
        if (palin(i, n, pdp, A))
            dp[n] = min(dp[n], 1 + solve(i - 1, dp, A, pdp));
    }
    return dp[n];
}

int Solution::minCut(string A) {
    int n = A.length();
    vector<int> dp(n, -1);
    vector<vector<int> > pdp;
    pdp.resize(n);
    for (int i = 0; i < n; i++)
        pdp[i].resize(n, -1);
    return solve(n - 1, dp, A, pdp);
}

