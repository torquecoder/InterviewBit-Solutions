int KMP(string S, string K)
{
    vector<int> T(K.size() + 1, -1);
	vector<int> matches;
    
	for(int i = 1; i <= K.size(); i++)
	{
		int pos = T[i - 1];
		while(pos != -1 && K[pos] != K[i - 1]) 
		    pos = T[pos];
		T[i] = pos + 1;
	}

	int sp = 0;
	int kp = 0;
	while(sp < S.size())
	{
		while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
		kp++;
		sp++;
		if(kp == K.size()) 
		    matches.push_back(sp - K.size());
	}
	if (matches.size() == 0)
	    return -1;
	return matches[0];
}



int Solution::strStr(const string &haystack, const string &needle) {
    if (haystack.length() == 0 || needle.length() == 0)
        return -1;
    return KMP(haystack, needle);
}

