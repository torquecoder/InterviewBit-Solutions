void Solution::reverseWords(string &A) {
    int n = A.length();
    stack<string> v;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == ' ')
            continue;
        string temp = "";
        while (i < n && A[i] != ' ')
        {
            temp += A[i];
            i++;
        }
        if (temp.size() > 0)
            v.push(temp);
    }
    A = "";
    while (v.size() != 1)
    {
        A += v.top();
        A += " ";
        v.pop();
    }
    A += v.top();
}
