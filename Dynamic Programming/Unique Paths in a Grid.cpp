int solve(int x, int y, vector<vector<int> > &dp, vector<vector<int> > &A)
{
    if (x < 0 || y < 0)
        return 0;
    if (x == 0 && y == 0 && A[x][y] == 0)
        return 1;
    if (x == 0 && y == 0 && A[x][y] == 1)
        return 0;
    if (A[x][y] == 1)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = solve(x - 1, y, dp, A) + solve(x, y - 1, dp, A);
    return dp[x][y];
}


int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > dp;
    dp.resize(n);
    for (int i = 0; i < n; i++)
        dp[i].resize(m, -1);
    return solve(n - 1, m - 1, dp, A);
}

