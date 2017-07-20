vector<int> ans;

void solve(int x, int A, int B)
{
    if (x > B)
        return;
    if (x >= A && x <= B)
        ans.push_back(x);
    int d = x % 10;
    if (d == 0)
        solve(x * 10 + 1, A, B);
    else if (d == 9)
        solve(x * 10 + 8, A, B);
    else
    {
        solve(x * 10 + d - 1, A, B);
        solve(x * 10 + d + 1, A, B);
    }
}

vector<int> Solution::stepnum(int A, int B) {
    ans.clear();
    for (int i = 1; i <= 9; i++)
        solve(i, A, B);
    if (A == 0)
        ans.push_back(0);
    sort(ans.begin(), ans.end());
    return ans;
}
