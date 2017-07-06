int Solution::jump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    int r = 1;
    for (int i = 0; i < n; i++)
    {
        int j;
        if (dp[i] == -1)
            continue;
        for (j = max(r, i + 1); j <= min(i + A[i], n - 1); j++)
            dp[j] = dp[i] + 1;
        r = j;
    }
    return dp[n - 1];
}

