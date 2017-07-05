/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int depth (TreeNode *root) 
{
    if (root == NULL) 
        return 0;
    return max (depth(root -> left), depth (root -> right)) + 1;
} 

int Solution::isBalanced(TreeNode* A) {
    if (A == NULL) 
        return 1;
    
    int left = depth(A->left);
    int right = depth(A->right);
    
    if (abs(left - right) <= 1 && isBalanced(A->left) && isBalanced(A->right))
        return 1;
    return 0;
}

