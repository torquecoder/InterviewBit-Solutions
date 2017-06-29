int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int ans = max(A[n - 1] * A[n - 2] * A[n - 3], A[0] * A[1] * A[n - 1]);
    return ans;
}

