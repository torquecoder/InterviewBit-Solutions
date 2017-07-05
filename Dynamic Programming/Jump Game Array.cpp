int Solution::canJump(vector<int> &A) {
    int n = A.size();
    int pos = n - 1;
    for(int i = n - 2; i >= 0; i--)
        if(i + A[i] >= pos)
            pos = i;
    return pos <= 0;
}

