int Solution::maxArr(vector<int> &a) {
    int n = a.size();
    int m1 = a[0], m2 = a[0], m3 = a[0], m4 = a[0];
    for (int i = 1; i < n; i++)
    {
        m1 = max(m1, a[i] + i);
        m2 = max(m2, a[i] - i);
        m3 = min(m3, a[i] + i);
        m4 = min(m4, a[i] - i);
    }
    int ans = max(m1 - m3, m2 - m4);
    return ans;
}
