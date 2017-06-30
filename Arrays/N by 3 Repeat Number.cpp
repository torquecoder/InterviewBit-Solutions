int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int elem1 = INT_MAX, elem2 = INT_MAX;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
    	if (cnt1 > 0 && A[i] == elem1)
    		cnt1++;
        else if (cnt2 > 0 && A[i] == elem2)
    		cnt2++;
    	else if (cnt1 == 0)
    	{
    		elem1 = A[i];
    		cnt1 = 1;
    	}
    	else if (cnt2 == 0)
    	{
    		elem2 = A[i];
    		cnt2 = 1;
    	}
    	else
    	{
    		cnt1--;
    		cnt2--;
    	}
    }
   int val, freq = 0;
    if (cnt1 == 0 && cnt2 == 0)
    	return -1;
    else 
        val = elem1;
	for (int i = 0; i < n; i++)
	{
    	if (A[i] == val)
    		freq++;
    }
    if (freq > n / 3)
    	return val;
    val = elem2;
    freq = 0;
    for (int i = 0; i < n; i++)
    {
    	if (A[i] == val)
    		freq++;
    }
    if (freq > n / 3)
    	return val;
    return -1;
}

