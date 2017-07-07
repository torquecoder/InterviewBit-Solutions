int solve(int x, vector<int> &dp)
{
    if (x <= 1)
        return 1;
    if (dp[x] != -1)
        return dp[x];
    dp[x] = 0;
    for (int i = 0; i < x; i++)
        dp[x] += solve(i, dp) * solve(x - i - 1, dp);
    return dp[x];
}

int Solution::numTrees(int A) {
    vector<int> dp(A + 1, -1);
    return solve(A, dp);
}

