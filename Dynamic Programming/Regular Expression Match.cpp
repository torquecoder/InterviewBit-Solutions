int match(string s, int i, string p, int j)
{

    if(i >= s.size() && j >= p.size())
        return 1;

    if(i == s.size() && j < p.size())
    {
        for(int t = j; t < p.size(); t++)
        {
            if(p[t] != '*')
                return 0;
        }
        return 1;
    }

    if(s[i] == p[j] || p[j] == '?')
        return match(s, i+1, p, j+1);

    if(p[j] == '*')
        return max(match(s, i+1, p, j), match(s, i, p, j+1));
}

int Solution::isMatch(const string &s, const string &p)
{
    int pat = p.size();
    int str = s.size();
    int i = 0, j = 0;
    int iIndex = -1, jIndex = -1;
    while (i < str)
    {
        if (s[i] == p[j] || (j < pat && p[j] == '?'))
        {
            i++;
            j++;
        }
        else if (p[j] == '*' && j < pat)
        {
            jIndex = j;
            iIndex = i;
            j++;
        }
        else if (jIndex != -1)
        {
            j = jIndex + 1;
            i = iIndex + 1;
            iIndex++;
        }
        else
            return 0;
    }
    while (j < pat && p[j] == '*')
        j++;
    if (j == pat)
        return 1;
    return 0;
}
