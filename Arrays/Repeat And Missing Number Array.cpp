# define LL long long

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    LL n = A.size();
    LL a, b;
    LL sum = n * (n + 1) / 2, square_sum = n * (n + 1) * (2 * n + 1) / 6;
    for (int i = 0; i < n; i++)
    {
        sum -= (LL)A[i];
        square_sum -= (LL)A[i] * (LL)A[i];
    }
    a = (square_sum / sum - sum) / 2;
    b = a + sum;
    vector<int> ans;
    ans.push_back(a);
    ans.push_back(b);
    return ans;
}
