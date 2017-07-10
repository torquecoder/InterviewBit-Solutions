int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    int hist[n + 1][m + 1];
 
    for (int i = 0; i < m; i++)
    {
        hist[0][i] = A[0][i];
        for (int j = 1; j < n; j++)
            hist[j][i] = (A[j][i] == 0) ? 0 : hist[j - 1][i]+1;
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> count(n + 1, 0);
        for (int j = 0; j < m; j++)
            count[hist[i][j]]++;
        int col_no = 0;
        for (int j = n; j >= 0; j--)
        {
            if (count[j] > 0)
            {
                for (int k = 0; k < count[j]; k++)
                {
                    hist[i][col_no] = j;
                    col_no++;
                }
            }
        }
    }
 
    int curr_area, max_area = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            curr_area = (j + 1) * hist[i][j];
            if (curr_area > max_area)
                max_area = curr_area;
        }
    }
    return max_area;
}

