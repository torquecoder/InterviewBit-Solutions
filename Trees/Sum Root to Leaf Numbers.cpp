/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 void dfs(TreeNode* A, int path_sum, int& sum)
 {
    path_sum *= 10;
    path_sum %= 1003;
    path_sum += A->val;
    path_sum %= 1003;
    if (A->left == NULL && A->right == NULL)
    {
        sum += path_sum;
        sum %= 1003;
        return;
    }
    if (A->left)
        dfs(A->left, path_sum, sum);
    if (A->right)
        dfs(A->right, path_sum, sum);
 }

int Solution::sumNumbers(TreeNode* A) {
   int sum = 0;
   dfs(A, 0, sum);
   return sum;
}
