int n1, n2;
vector<vector<int> > dp;
int solve(int x, int y, string &A, string &B)
{
    if (x == -1)
        return y + 1;
    if (y == -1)
        return x + 1;
    if (dp[x][y] != -1)
        return dp[x][y];
    int ans = 1e7;
    if (A[x] == B[y])
        ans = solve(x - 1, y - 1, A, B);
    ans = min(ans, min(1 + solve(x, y - 1, A, B), min(1 + solve(x - 1, y, A, B),1 + solve(x - 1, y - 1, A, B))));
    return dp[x][y] = ans;
}

int Solution::minDistance(string A, string B) {
    n1 = A.length();
    n2 = B.length();
    dp.resize(n1 + 1);
    for (int i = 0; i <= n1; i++)
    {
        dp[i].resize(n2 + 1);
        for (int j = 0; j <= n2; j++)
            dp[i][j] = -1;
    }
    return solve(n1 - 1, n2 - 1, A, B);
}
