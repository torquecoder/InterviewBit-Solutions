/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs(TreeNode* A, int len)
{
    len++;
    if (A->left == NULL && A->right == NULL)
        return len;
    int ans = 0;
    if (A->right)
        ans = dfs(A->right, len);
    if (A->left)
        ans = max(ans, dfs(A->left, len));
    return ans;
}

int Solution::maxDepth(TreeNode* A) {
    return dfs(A, 0);
}
