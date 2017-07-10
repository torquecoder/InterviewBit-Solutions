const long long MOD = 1e9 + 7;
long long solve(int x, vector<long long> &dp)
{
    if (x == 0)
        return 1;
    if (x == 2)
        return 1;
    if (dp[x] != -1)
        return dp[x];
    dp[x] = 0;
    for (int i = 0; i <= x - 2; i += 2)
    {
        dp[x] += (solve(i, dp) * solve(x - 2 - i, dp)) % MOD;
        dp[x] %= MOD;
    }
    return dp[x];
}

int Solution::chordCnt(int A){
    int n = 2 * A;
    vector<long long> dp(n + 1, -1);
    return solve(n, dp);
}

