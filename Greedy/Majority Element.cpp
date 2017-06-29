int Solution::majorityElement(const vector<int> &A) {
    int idx = 0;
    int cnt = 1;
    for (int i = 1; i < A.size(); i++) 
    {
        A[idx] == A[i] ? cnt++ : cnt--;
        if (cnt == 0) 
        {
            idx = i;
            cnt = 1;
        }
    }
    return A[idx];
}

