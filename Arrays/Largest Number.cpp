# include <bits/stdc++.h>

bool compare(string A, string B)
{
    string s1 = A + B;
    string s2 = B + A;
    if (s1 < s2)
        return true;
    return false;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<string> v;
    for (int i = 0; i < A.size(); i++)
        v.push_back(to_string(A[i]));
    sort(v.begin(), v.end(), compare);
    string str = "";
    for (int i = A.size() - 1; i >= 0; i--)
        str += v[i];
    int i = 0;
    while (i < str.length() && str[i] == '0')
        i++;
    if (i == str.length())
        return "0";
    else
    {
        string ans = "";
        for (int j = i; j < str.length(); j++)
            ans += str[j];
        return ans;
    }
}
