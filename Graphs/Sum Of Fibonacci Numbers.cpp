int solve(int n)
{
    if (n == 0)
        return 0;
    int a = 0, b = 1, c;
    while (b <= n)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return 1 + solve(n - a);
}

int Solution::fibsum(int A) {
    return solve(A);
}

