void dfs(int n, int p, int &dist, vector<vector<int> > &adj, vector<int> &dp)
{
    int mx1 = 0, mx2 = 0;
    for (auto i = adj[n].begin(); i < adj[n].end(); i++)
    {
        if (*i == p)
            continue;
        dfs(*i, n, dist, adj, dp);
        if (dp[*i] >= mx1)
        {
            mx2 = mx1;
            mx1 = dp[*i];
        }
        else if (dp[*i] >= mx2)
            mx2 = dp[*i];
    }
    dp[n] = 1 + mx1;
    dist = max(dist, mx1 + mx2 + 1);
}   

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int> > adj;
    adj.resize(40000);
    for (int i = 0; i < n; i++)
    {
        if (A[i] != -1)
        {
            adj[A[i]].push_back(i);
            adj[i].push_back(A[i]);
        }
    }
    int dist = 0;
    vector<int> dp(n);
    dfs(0, -1, dist, adj, dp);
    return dist - 1;
}

