int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    if (n == 0)
        return 0;
    int buy[n];
    int sell[n];
    buy[0] = A[0];
    sell[n - 1] = A[n - 1];
    for (int i = 1; i < n; i++)
        buy[i] = min(buy[i - 1], A[i]);
    for (int i = n - 2; i >=0 ; i--)
        sell[i] = max(sell[i + 1], A[i]);
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, sell[i] - buy[i - 1]);
    return ans;
    
}

