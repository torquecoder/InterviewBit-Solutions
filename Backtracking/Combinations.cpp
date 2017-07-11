
void generate(int n, int k, vector<int> &temp, vector<vector<int> > &ans)
{
    if (temp.size() == k)    
    {
        ans.push_back(temp);
        return;
    }
    if (temp.size() == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            temp.push_back(i);
            generate(n, k, temp, ans);
            temp.pop_back();
        }
    }
    else
    {
        int x = temp.back();
        for (int i = x + 1; i <= n; i++)
        {
            temp.push_back(i);
            generate(n, k, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    vector<int> temp;
    vector<vector<int> > ans;
    generate(n, k, temp, ans);
    return ans;
}

