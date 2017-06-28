/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* A) {
    if (A == NULL) 
        return A;  
    TreeNode *rtree = A->right, *temp;
    A->right = NULL;
    if (A->left != NULL) 
    {  
        temp = flatten(A->left);  
        A->right = temp;
        A->left = NULL;
    }   
    rtree = flatten(rtree);
    temp = A;
    while (temp->right != NULL)
        temp = temp->right;
    temp->right = rtree;
    return A;  
}

