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
    ListNode *head = NULL, *temp;
    int flag = 0;
    while (A != NULL)
    {
        if (A->next != NULL && A->val == A->next->val)
        {
            int value = A->val;
            while (A != NULL && A->val == value)
                A = A->next;
        }
        else
        {
            if (!flag)
            {

                head = A;
                temp = A;
                flag = 1;
            }
            else
            {
                temp->next = A;
                temp = temp->next;
            }
            A = A->next;
        }
    }
    if (head != NULL)
        temp->next = NULL;
    return head;
}
