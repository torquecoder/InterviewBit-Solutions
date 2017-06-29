/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int  dfs(TreeNode* A, TreeNode* B)
{
    if (A == NULL && B == NULL)
        return 1;
    if (A == NULL || B == NULL)
        return 0;
    if (A->val != B->val)
        return 0;
    if (!dfs(A->left, B->right))
        return 0;
    if (!dfs(A->right, B->left))
        return 0;
    return 1;
}

int Solution::isSymmetric(TreeNode* A) {
    return dfs(A, A);
}

