int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n = gas.size();
    int j;
    for (int i = 0; i < n; i += j) 
    {
        int left = 0;
        for (j = 1; j <= n; j++) 
        {
            int k = (i + j - 1) % n;
            left += gas[k] - cost[k];
            if (left < 0)
                break;
        }
        if (j > n)
            return i;
    }
    return -1;
}

