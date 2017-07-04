#define MOD 10000003
long long  solve(string A, int k)
{
    int n = A.length();
    long long ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] == 'x')
        {
           ret += (long long)abs(i - k);
           k++;
        }
    }
    return ret;
}
int Solution::seats(string A) {
    int n = A.length();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(A[i] == 'x')
            cnt++;
    }
    int median, curr = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 'x')
        {
            curr++;
            if (curr == (cnt / 2) + 1)
            {
                median = i;
                break;
            }
        }
    }
    if(cnt == 0)
        return 0;
        
    string B = A.substr(median, n - median);
    string C = A.substr(0, median);
    for(int i = 0; i < median / 2; i++)
        swap(C[i], C[median - 1 - i]);
    
    long long ans;
    ans = solve(B, 0);
    ans %= MOD;
    ans += solve(C, 0);
    ans %= MOD;
    return (int)ans;  
}
