bool valid(int x, int y, int n, int m, vector<string> &A, vector<vector<int> > &v)
{
    if (x >= 0 && x < n && y >= 0 && y < m && !v[x][y] && A[x][y] == 'X')
        return true;
    return false;
}

void dfs(int x, int y, vector<string> &A, vector<vector<int> > &v)
{
    int n = A.size();
    int m = A[0].size();
    v[x][y] = 1;
    if (valid(x + 1, y, n, m, A, v))
        dfs(x + 1, y, A, v);
    if (valid(x - 1, y, n, m, A, v))
        dfs(x - 1, y, A, v);
    if (valid(x, y + 1, n, m, A, v))
        dfs(x, y + 1, A, v);
    if (valid(x, y - 1, n, m, A, v))
        dfs(x, y - 1, A, v);
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    int ans = 0;
    vector<vector<int> > v(n);
    for (int i = 0; i < n; i++)
        v[i].resize(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'X' && !v[i][j])
                dfs(i, j, A, v), ans++;
        }
    }
    return ans;
}
