/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> st;
void pushAll(TreeNode *node)
{
    for (; node != NULL; st.push(node), node = node->left);
}

BSTIterator::BSTIterator(TreeNode *root) {
    pushAll(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !st.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *top = st.top();
    st.pop();
    pushAll(top->right);
    return top->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
