vector<vector<int> > adj;
vector<int> a, cap;
bool compare(const vector<int>& v1, const vector<int>& v2 )
{
    return v1[2] < v2[2];
}

int parent(int x)
{
    while (a[x] != x)
    {
        a[x] = a[a[x]];
        x = a[x];
    }
    return x;
}

void wunion(int u, int v)
{
    if (cap[u] >= cap[v])
    {
        a[v] = u;
        cap[u] += cap[v];
    }
    else
    {
        a[u] = v;
        cap[v] += cap[u];
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    sort(B.begin(), B.end(), compare);
    a.resize(A + 1);
    cap.resize(A + 1);
    for (int i = 1; i <= A; i++)
    {
        a[i] = i;
        cap[i] = 1;
    }
    int ans = 0;
    for (int i = 0; i < B.size(); i++)
    {
        if (parent(B[i][0]) != parent(B[i][1]))
        {
            wunion(parent(B[i][0]), parent(B[i][1]));
            ans += B[i][2];
        }
    }
    return ans;
}
