string Solution::addBinary(string A, string B) {
    string ans = "";
    int c = 0, i = A.size() - 1, j = B.size() - 1;
    while (i >= 0 || j >= 0 || c == 1)
    {
        c += i >= 0 ? A[i --] - '0' : 0;
        c += j >= 0 ? B[j --] - '0' : 0;
        ans = char(c % 2 + '0') + ans;
        c /= 2;
    }
    return ans;
}

