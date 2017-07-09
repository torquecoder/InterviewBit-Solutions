vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size();
    vector<vector<int> > ans;
    vector<int> temp;
    int k = 1;
    unordered_map<string, int> m;
    for (int i = 0; i < n; i++) 
    {
        string t = A[i]; 
        sort(t.begin(), t.end());
        if (m[t] == 0)
        {
            m[t] = k;
            ans.push_back(temp);
            ans[k - 1].push_back(i + 1);
            k++;
        }
        else
            ans[m[t] - 1].push_back(i + 1);
    }
    return ans;
}

