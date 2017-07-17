void solve(int idx, vector<int> &A, vector<vector<int> > &ans, vector<int> &temp)
{
    if (idx == A.size())
    {
        ans.push_back(temp);
        return;
    }
    
    solve(idx + 1, A, ans, temp);
    
    temp.push_back(A[idx]);
    solve(idx + 1, A, ans, temp);
    temp.pop_back();
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int> > ans;
    vector<int> temp;
    solve(0, A, ans, temp);
    sort(ans.begin(), ans.end());
    return ans;
}

