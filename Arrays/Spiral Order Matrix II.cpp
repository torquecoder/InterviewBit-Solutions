vector<vector<int> > Solution::generateMatrix(int n) {
    int ans[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = 0;
    int dir = 1;
    int posi = 0, posj = 0;
    ans[posi][posj] = 1;
    for (int i = 2; i <= n * n; i++)
    {
        if (dir == 1)
        {
            if (posj + 1 < n && ans[posi][posj + 1] == 0)
            {
                posj++;
                ans[posi][posj] = i;
            }
            else
            {
                dir = 2;
                posi++;
                ans[posi][posj] = i;
            }
        }
        else if (dir == 2)
        {
            if (posi + 1 < n && ans[posi + 1][posj] == 0)
            {
                posi++;
                ans[posi][posj] = i;
            }
            else
            {
                dir = 3;
                posj--;
                ans[posi][posj] = i;
            }
        }
        else if (dir == 3)
        {
            if (posj - 1 >= 0 && ans[posi][posj - 1] == 0)
            {
                posj--;
                ans[posi][posj] = i;
            }
            else
            {
                dir = 4;
                posi--;
                ans[posi][posj] = i;
            }
        }
        else if (dir == 4)
        {
            if (posi - 1 >= 0 && ans[posi - 1][posj] == 0)
            {
                posi--;
                ans[posi][posj] = i;
            }
            else
            {
                dir = 1;
                posj++;
                ans[posi][posj] = i;
            }
        }

    }

    vector<vector<int> > ret;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
            temp.push_back(ans[i][j]);
        ret.push_back(temp);
    }
    return ret;
}
