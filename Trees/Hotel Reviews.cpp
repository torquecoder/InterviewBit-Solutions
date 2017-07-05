bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        if (a.second > b.second)
            return false;
        return true;
    }
    return a.first > b.first;
}



vector<int> Solution::solve(string A, vector<string> &B) {
    unordered_map<string, int> good;
    for (int i = 0; i < A.size(); i++)
    {
        string temp = "";
        while (i < A.size() && A[i] >= 'a' && A[i] <= 'z')
        {
            temp += A[i];
            i++;
        }
        good[temp] = 1;
    }
    vector<pair<int, int> > ans;
    for (int i = 0; i < B.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < B[i].size(); j++)
        {
            string temp = "";
            while (j < B[i].size() && B[i][j] >= 'a' && B[i][j] <= 'z')
            {
                temp += B[i][j];
                j++;
            }
            if (good[temp] == 1)
                cnt++;
        }
        ans.push_back({cnt, i});
    }
    sort(ans.begin(), ans.end(), compare);
    vector<int> ret;
    for (int i = 0; i < ans.size(); i++)
        ret.push_back(ans[i].second);
    return ret;
}

