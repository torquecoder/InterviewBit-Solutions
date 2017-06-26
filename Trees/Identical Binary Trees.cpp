/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int dfs(TreeNode* A, TreeNode* B)
{
    if (A == NULL && B == NULL)
        return 1;
    if (A == NULL)
        return 0;
    if (B == NULL)
        return 0;
    if (A->val != B->val)
        return 0;
    if (A->left)
    {
        if (B->left == NULL)
            return 0;
        int x = dfs(A->left, B->left);
        if (!x)
            return 0;
    }
    else if (B->left)
        return 0;
    if (A->right)
    {
        if (B->right == NULL)
            return 0;
        int x = dfs(A->right, B->right);
        return x;
    }
    else if (B->right)
        return 0;
    return 1;
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
   return dfs(A, B);
}
