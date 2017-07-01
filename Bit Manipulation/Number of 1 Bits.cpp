int Solution::numSetBits(unsigned int A) {
    int ans = 0;
    while (A)
    {
        if (A % 2)
            ans++;
        A /= 2;
    }
    return ans;
}

