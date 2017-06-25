/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if (A == NULL)
        return A;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode*));
    head->next = NULL;
    head->val = A->val;
    ListNode* temp = head;
    while (A != NULL)
    {
        if (A->val != temp->val)
        {
            temp->next = A;
            temp = temp->next;
        }
        A = A->next;
    }
    temp->next = NULL;
    return head;
}
