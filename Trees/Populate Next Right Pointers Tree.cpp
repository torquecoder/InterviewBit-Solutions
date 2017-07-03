/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void Solution::connect(TreeLinkNode* A) {
    TreeLinkNode* down = NULL; 
    TreeLinkNode* prev = NULL; 
    TreeLinkNode* curr = A; 

    while (curr != NULL) 
    {
        while (curr != NULL) 
        {
            if (curr->left != NULL) 
            {
                if (prev != NULL)
                    prev->next = curr->left;
                else
                    down = curr->left;
                prev = curr->left;
            }

            if (curr->right != NULL) 
            {
                if (prev != NULL) 
                    prev->next = curr->right;
                else 
                    down = curr->right;
                prev = curr->right;
            }
            curr = curr->next;
        }
        curr = down;
        down = NULL;
        prev = NULL;
    }
    
    
}

