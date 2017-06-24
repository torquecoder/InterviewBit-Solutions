string Solution::longestPalindrome(string A) {
    int n = A.length();
    int ans = 0;
    int sl, sr;
    for (int i = 0; i < n; i++)
    {
        int l = i - 1;
        int r = i + 1;
        int len = 1;
        while (l >= 0 && r < n && l <= r && A[l] == A[r])
        {
            len += 2;
            l--;
            r++;
        }
        if (len > ans)
        {
            ans = len;
            sl = l + 1;
            sr = r - 1;
        }
        l = i;
        r = i + 1;
        len = 0;
        while (l >= 0 && r < n && l <= r && A[l] == A[r])
        {
            len += 2;
            l--;
            r++;
        }
        if (len > ans)
        {
            ans = len;
            sl = l + 1;
            sr = r - 1;
        }
    }
    return A.substr(sl, ans);
}
