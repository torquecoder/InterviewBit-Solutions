string Solution::convertToTitle(int A) {
    string s = "";
    while (A > 0)
    {
        int rem = A % 26;
        if (rem == 0)
        {
            s += 'Z';
            A = (A / 26) - 1;
        }
        else
        {
            s += (rem - 1) + 'A';
            A = A / 26;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}

