int Solution::solve(const vector<int> &A) {
    int ans = 2;
    int n = A.size();
    if (n == 1)
        return 1;
    int dp[n][n];
    vector<int> B = A;
    sort(B.begin(), B.end());
    
    for(int i = 0; i < n - 1; i++)  
        for(int j = i; j < n; j++)  
            dp[i][j] = 2;  
            
    for(int j = n; j >= 0; j--)
    {  
        int i = j - 1, k = j + 1;  
        while(i >= 0 && k < n)
        {  
            if(B[i] + B[k] < 2 * B[j])  
                k++;  
            else if (B[i] + B[k] > 2 * B[j])  
                i--;  
            else
            {  
                dp[i][j] = dp[j][k] + 1;  
                ans = max(ans, dp[i][j]);  
                i--;  
                k++;  
            }  
        }  
    }    
    return ans;  
}

