vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int l = -1, r = -1;
    int left = 0, right = A.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] == B)
        {
            l = mid;
            right = mid - 1;
        }
        else if (A[mid] > B)
            right = mid - 1;
        else
            left = mid + 1;
    }

    left = 0, right = A.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] == B)
        {
            r = mid;
            left = mid + 1;
        }
        else if (A[mid] > B)
            right = mid - 1;
        else
            left = mid + 1;
    }

    vector<int> ans;
    ans.push_back(l);
    ans.push_back(r);
    return ans;
}
