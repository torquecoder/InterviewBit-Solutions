int Solution::numDecodings(string A) {
    int n = A.length();
    vector<int> dp(n, 0);
    if (A[0] - '0' != 0)
        dp[0] = 1;
    else
        dp[0] = 0;
    if (n == 1)
        return dp[0];
    if ((A[0] - '0') * 10 + (A[1] - '0') <= 26 && (A[0] - '0') * 10 + (A[1] - '0') >= 10)
        dp[1] = 1;
    if (A[1] - '0' != 0)
        dp[1] += dp[0];
    for (int i = 2; i < n; i++)
    {
        if (A[i] - '0' != 0)
            dp[i] += dp[i - 1];
        if ((A[i - 1] - '0') * 10 + (A[i] - '0') <= 26 && (A[i - 1] - '0') * 10 + (A[i] - '0') >= 10)
            dp[i] += dp[i - 2];
    }
    return dp[n - 1];
}

