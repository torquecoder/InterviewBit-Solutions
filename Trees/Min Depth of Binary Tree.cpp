/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void dfs(TreeNode* A, int cnt, int& ans)
{
    cnt++;
    if (A->left == NULL && A->right == NULL)
    {
        ans = min(ans, cnt);
        return;
    }
    if (A->left)
        dfs(A->left, cnt, ans);
    if (A->right)
        dfs(A->right, cnt, ans);
}

int Solution::minDepth(TreeNode* A) {
    int ans = INT_MAX;
    dfs(A, 0, ans);
    return ans;
}
