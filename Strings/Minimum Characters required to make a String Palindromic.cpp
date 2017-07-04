vector<int> computeLPSArray(string s)
{
    int M = s.length();
    vector<int> lps(M);
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else 
        {
            if (len != 0)
                len = lps[len-1];
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int go(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    string concat = s + "$" + rev;
    vector<int> lps = computeLPSArray(concat);
    return (s.length() - lps.back());
}

int Solution::solve(string A) {
    return go(A);
}

