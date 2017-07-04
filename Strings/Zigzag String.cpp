string Solution::convert(string A, int B) {
    int n = A.length();
    string ans = "";
    if (B == 1)
        return A;
    for (int i = 1; i <= B; i++)
    {
        int idx1 = 2 * (B - i);
        if (idx1 == 0)
            idx1 = 2 * (B - 1);
        int idx2 = 2 * (B - 1) - idx1;
        if (idx2 == 0)
            idx2 = 2 * (B - 1);
        int ok = 0;
        for (int j = i - 1; j < n;)
        {
            ans += A[j];
            if (!ok)
                j += idx1;
            else
                j += idx2;
            ok ^= 1;
        }
    }
    return ans;
}

