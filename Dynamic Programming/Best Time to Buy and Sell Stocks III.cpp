int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    int dp0 = INT_MIN;
    int dp1 = 0;
    int dp2 = INT_MIN;
    int dp3 = 0;
    for(int i = 0; i < n; i++)
    {
        dp0 = max(dp0, -A[i]);
        dp1 = max(dp1, dp0 + A[i]);
        dp2 = max(dp2, dp1 - A[i]);
        dp3 = max(dp3, dp2 + A[i]);
    }
    return max(max(0, dp1), dp3);
}

