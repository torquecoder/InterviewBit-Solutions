bool valid(int x, int y, vector<vector<char> > &A, vector<vector<int> > &v)
{
    int n = A.size();
    int m = A[0].size(); 
    if (x >= 0 && x < n && y >= 0 && y < m && A[x][y] == 'O' && !v[x][y])
        return true;
    return false;
}

void dfs(int x, int y, vector<vector<char> > &A, vector<vector<int> > &v)
{
    v[x][y] = 1;
    if (valid(x + 1, y, A, v))
        dfs(x + 1, y, A, v);
    if (valid(x - 1, y, A, v))
        dfs(x - 1, y, A, v);
    if (valid(x, y + 1, A, v))
        dfs(x, y + 1, A, v);
    if (valid(x, y - 1, A, v))
        dfs(x, y - 1, A, v);
}

void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<int> > v(n);
    for (int i = 0; i < n; i++)
        v[i].resize(m, 0);
    for (int i = 0; i < m; i++)
    {
        if (valid(0, i, A, v))
            dfs(0, i, A, v);
        if (valid(n - 1, i, A, v))
            dfs(n - 1, i, A, v);
    }
    for (int i = 0; i < n; i++)
    {
        if (valid(i, 0, A, v))
            dfs(i, 0, A, v);
        if (valid(i, m - 1, A, v))
            dfs(i, m - 1, A, v);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (A[i][j] == 'O' && !v[i][j])
                A[i][j] = 'X';
    }
}

