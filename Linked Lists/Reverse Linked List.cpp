/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    if (A == NULL)
        return A;
    ListNode* prev = NULL;
    while (A != NULL)
    {
        ListNode* temp = A->next;
        A->next = prev;
        prev = A;
        A = temp;
    }
    return prev;
}
