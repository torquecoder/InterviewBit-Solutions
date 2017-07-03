int Solution::minimumTotal(vector<vector<int> > &A) {
    vector<int> dp = A[A.size()-1];
    for (int i = A.size() - 2; i >= 0 ; i--)
        for (int j = 0; j < A[i].size() ; j++)
            dp[j] = A[i][j] + min(dp[j], dp[j + 1]);
    return dp[0];
}

