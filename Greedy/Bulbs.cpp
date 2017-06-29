int Solution::bulbs(vector<int> &A) {
    int ans = 0;
    int on = 1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != on)
        {
            ans++;
            on ^= 1;
        } 
    }
    return ans;
}

