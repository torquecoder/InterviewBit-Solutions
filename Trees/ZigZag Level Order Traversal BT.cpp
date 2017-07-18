/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<TreeNode*> > ans;
    vector<TreeNode*> temp;
    temp.push_back(A);
    ans.push_back(temp);
    vector<TreeNode*> temp1;
    int dir = 0;
    while (!temp.empty())
    {
        if (dir == 0)
        {
            int sz = temp.size();
            for (int i = sz - 1; i >= 0; i--)
            {
                if (temp[i]->right)
                    temp1.push_back(temp[i]->right);
                if (temp[i]->left)
                    temp1.push_back(temp[i]->left);
            }

        }
        else
        {
            int sz = temp.size();
            for (int i = sz - 1; i >= 0; i--)
            {
                if (temp[i]->left)
                    temp1.push_back(temp[i]->left);
                if (temp[i]->right)
                    temp1.push_back(temp[i]->right);
            }
        }
        if (!temp1.empty())
            ans.push_back(temp1);
        temp = temp1;
        temp1.clear();
        dir ^= 1;
    }
    vector<vector<int> > ret;
    vector<int> tt;
    for (int i = 0; i < ans.size(); i++)
    {
        tt.clear();
        for (int j = 0; j < ans[i].size(); j++)
            tt.push_back(ans[i][j]->val);
        ret.push_back(tt);
    }
    return ret;
}
