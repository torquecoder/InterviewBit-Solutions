vector<int> Solution::twoSum(const vector<int> &A, int B) {
    map<int, int> pos;
    int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (pos[B - A[i]])
        {
            ans.push_back(pos[B - A[i]]);
            ans.push_back(i + 1);
            return ans;
        }
        if (!pos[A[i]])
            pos[A[i]] = i + 1;
        
    }
    return ans;
}

