int solve(int x, int y, vector<vector<int> > &dp, vector<vector<int> > &A, int n)
{
    if (y >= n)
        return 0;
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = max(A[x][y] + solve(0, y + 2, dp, A, n), 
    max(A[x][y] + solve(1, y + 2, dp, A, n), max(solve(x, y + 1, dp, A, n), solve(x^1, y + 1, dp, A, n))));
    return dp[x][y];
}

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<vector<int> > dp(2);
    dp[0].resize(n, -1);
    dp[1].resize(n, -1);
    return max(solve(0, 0, dp, A, n), solve(1, 0, dp, A, n));
}

