int Solution::maxProfit(const vector<int> &A) {
    int ans = 0;
    int n = A.size();
    if (n == 0)
        return 0;
    for (int i = 0; i < n - 1; i++) 
        if (A[i + 1] > A[i]) 
            ans += A[i + 1] - A[i];
    return ans;
}

