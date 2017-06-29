/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int> > ans;
    vector<int> temp;
    queue<TreeNode*> q;
    queue<int> level;
    if(A == NULL)
        return ans;
    
    q.push(A);
    level.push(0);
    while (!q.empty())
    {
        TreeNode* curr = q.front();
        int lev = level.front();
        q.pop();
        level.pop();
        if (ans.size() != lev + 1)
            ans.push_back(temp);
        ans[lev].push_back(curr->val);
        if (curr->left != NULL)
        {
            q.push(curr->left);
            level.push(lev + 1);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
            level.push(lev + 1);
        }
    }
    
    return ans;
}

