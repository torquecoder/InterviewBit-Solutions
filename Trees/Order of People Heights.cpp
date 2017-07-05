void build_segtree(int idx, int l, int r, vector<int> &seg_tree)
{
    if (l > r)
        return;
    if (l == r)
    {
        seg_tree[idx] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build_segtree(idx * 2 + 1, l, mid, seg_tree);
    build_segtree(idx * 2 + 2, mid + 1, r, seg_tree);
    seg_tree[idx] = seg_tree[2 * idx + 1] + seg_tree[2 * idx + 2];
}

int query(int idx, int l, int r, int space, vector<int> &seg_tree)
{
    if (l > r)
        return 0;
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    if (space <= seg_tree[2 * idx + 1])
        return query(2 * idx + 1, l, mid, space, seg_tree);
    else
        return query(2 * idx + 2, mid + 1, r, space - seg_tree[2 * idx + 1], seg_tree);
}

void update(int idx, int l, int r, int pos, vector<int> &seg_tree)
{
    if (l == r)
    {
        seg_tree[idx] = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(idx * 2 + 1, l, mid, pos, seg_tree);
    else
        update(idx * 2 + 2, mid + 1, r, pos, seg_tree);
    seg_tree[idx] = seg_tree[2 * idx + 1] + seg_tree[2 * idx + 2];
}

vector<int> Solution::order(vector<int> &heights, vector<int> &infronts) {
    int n = heights.size();
    vector<pair<int,int> > v;
    for (int i = 0; i < n; i++)
        v.push_back({heights[i], infronts[i]});
    sort(v.begin(), v.end());
    vector<int> seg_tree;
    seg_tree.resize(4 * n + 1);
    build_segtree(0, 0, n - 1, seg_tree);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int pos = query(0, 0, n - 1, v[i].second + 1, seg_tree);
        ans[pos] = v[i].first;
        update(0, 0, n - 1, pos, seg_tree);
    }
    return ans;
}

