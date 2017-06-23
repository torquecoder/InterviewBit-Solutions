string Solution::longestCommonPrefix(vector<string> &A) {
    int flag = 1;
    int idx = 0;
    while (flag)
    {
        if (A[0].length() < idx + 1)
            break;
        char s = A[0][idx];
        for (int i = 1; i < A.size(); i++)
        {
            if (A[i].length() < idx + 1 || A[i][idx] != s)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            idx++;
    }
    return A[0].substr(0, idx);
}
