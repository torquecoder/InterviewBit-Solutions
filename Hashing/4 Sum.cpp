vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    map<int, vector<pair<int, int> > > sum;
    vector<vector<int> > ans;
    set<vector<int> > s; 
    int n = A.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            sum[A[i] + A[j]].push_back({i, j});
    for (auto i = sum.begin(); i != sum.end(); i++)
    {
        for (auto j = sum[B - (i->first)].begin(); j != sum[B - (i->first)].end(); j++)
        {
            for (auto k = sum[i->first].begin(); k != sum[i->first].end(); k++)
            {
                vector<int> temp;
                if ((*j).first != (*k).first && (*j).first != (*k).second 
                && (*j).second != (*k).first && (*j).second != (*k).second)
                {
                    temp.push_back(A[(*j).first]);
                    temp.push_back(A[(*j).second]);
                    temp.push_back(A[(*k).first]);
                    temp.push_back(A[(*k).second]);
                    sort(temp.begin(), temp.end());
                    s.insert(temp);    
                }
                
            }
        }
    }
    for (auto i = s.begin(); i != s.end(); i++)
        ans.push_back(*i);
    return ans;
}

