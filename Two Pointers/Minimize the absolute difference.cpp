int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0, ans = INT_MAX;
    while (i < A.size() && j < B.size() && k < C.size())
    {
        int mn = min(A[i], min(B[j], C[k]));
        int mx = max(A[i], max(B[j], C[k]));
        if (ans > (mx - mn))
            ans = mx - mn;
        if (ans == 0)
            break;
        if (A[i] == mn)
            i++;
        else if (B[j] == mn)
            j++;
        else
            k++;
    }
    return ans;
}
