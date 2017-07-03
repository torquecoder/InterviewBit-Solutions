/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int length(ListNode* A)
{
    int len = 0;
    while (A != NULL)
    {
        len++;
        A = A->next;
    }
    return len;
}

ListNode* temp;

TreeNode* dfs(int n)
{
    if (n <= 0)
        return NULL;
    TreeNode* left = dfs(n / 2);
    TreeNode* root = new TreeNode(temp->val);
    root->left = left;
    temp = temp->next;
    root->right = dfs(n - n / 2 - 1);
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    if (A == NULL)
        return NULL;
    int n = length(A);
    temp = A;
    return dfs(n);
}

