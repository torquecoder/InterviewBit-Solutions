/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::recoverTree(TreeNode* A) {
 
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;   
    stack<TreeNode*> st;
    
    TreeNode* curr = A;
    while (1)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            if (prev != NULL && prev->val > curr->val)
            {
                if (first == NULL)
                    first = prev;
                second = curr;
            }
            prev = curr;
            curr = curr->right;
        }
        if(st.empty() &&  curr == NULL){
           break; 
        }
    }

    vector<int> ans;
    ans.push_back(min(first->val, second->val));
    ans.push_back(max(first->val, second->val));
    return ans;
}

