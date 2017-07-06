# define MOD 1003

int solve(int n, int m , int t, string &A, vector<vector<vector<int> > > &dp)
{
    if (n == m)
    {
        if (A[n] == 'T')
        {
            dp[n][m][0] = 1;
            dp[n][m][1] = 0;
        }
        else
        {
            dp[n][m][0] = 0;
            dp[n][m][1] = 1;
        }
    }
    if (dp[n][m][t] != -1)
        return dp[n][m][t];
    dp[n][m][t] = 0;
    int val;
    if (A[n] == 'T')
        val = 1;
    else
        val = 0;
    for (int i = n; i <= m - 2; i += 2)
    {

        if (A[i + 1] == '|')
        {
            if (t == 0)
            {
                dp[n][m][t] += (solve(n, i, 0, A, dp) * solve(i + 2, m, 0, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
                dp[n][m][t] += (solve(n, i, 0, A, dp) * solve(i + 2, m, 1, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
                dp[n][m][t] += (solve(n, i, 1, A, dp) * solve(i + 2, m, 0, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
            }
            else
            {
                dp[n][m][t] += (solve(n, i, 1, A, dp) * solve(i + 2, m, 1, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
            }
        }
        else if (A[i + 1] == '&')
        {
            if (t == 0)
            {
                dp[n][m][t] += (solve(n, i, 0, A, dp) * solve(i + 2, m, 0, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
            }
            else
            {
                dp[n][m][t] += (solve(n, i, 1, A, dp) * solve(i + 2, m, 1, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
                dp[n][m][t] += (solve(n, i, 0, A, dp) * solve(i + 2, m, 1, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
                dp[n][m][t] += (solve(n, i, 1, A, dp) * solve(i + 2, m, 0, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
            }
        }
        else if (A[i + 1] == '^')
        {
            if (t == 0)
            {
                dp[n][m][t] += (solve(n, i, 0, A, dp) * solve(i + 2, m, 1, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
                dp[n][m][t] += (solve(n, i, 1, A, dp) * solve(i + 2, m, 0, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
            }
            else
            {
                dp[n][m][t] += (solve(n, i, 0, A, dp) * solve(i + 2, m, 0, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
                dp[n][m][t] += (solve(n, i, 1, A, dp) * solve(i + 2, m, 1, A, dp)) % MOD;
                dp[n][m][t] %= MOD;
            }
        }
    }
    return dp[n][m][t];
}

int Solution::cnttrue(string A) {
    int n = A.length();
    vector<vector<vector<int> > > dp;
    dp.resize(n);
    for (int i = 0; i < n; i++)
    {
        dp[i].resize(n);
        for (int j = 0; j < n; j++)
            dp[i][j].resize(2, -1);
    }
    
    return solve(0, n - 1, 0, A, dp);
    
}

