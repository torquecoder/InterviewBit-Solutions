int Solution::numDistinct(string S, string T) {
    int n = S.length();
    int m = T.length();
    vector<vector<int> > dp;
    dp.resize(m + 1);
    for (int i = 0; i <= m; i++)
        dp[i].resize(n + 1, 0);
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if(T[i] == S[j]) 
                dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
            else
                dp[i + 1][j + 1] = dp[i + 1][j];
        }
    }
    return dp[m][n];
}

