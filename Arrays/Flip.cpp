vector<int> Solution::flip(string s) {
    int n = s.length();
    int cnto = 0, cntz = 0, mn = INT_MAX, sum[n + 1], minidx = n, minsum = 0;
    int pos[n + 1];
    sum[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
            cntz++;
        else
            cnto++;
        sum[i] = cntz - cnto;
        if (sum[i] <= minsum)
        {
            minsum = sum[i];
            minidx = i;
        }
        pos[i] = minidx;
    }
    int ans = 0, l, r;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            continue;
        int temp_ans = sum[i] - sum[pos[i]];
        if (temp_ans > ans)
        {
            l = i;
            r = pos[i] - 1;
            ans = temp_ans;
        }
    }
    vector<int> ret;
    if (ans == 0)
        return ret;
    else
    {
        ret.push_back(l + 1);
        ret.push_back(r + 1);
        return ret;
    }
}
