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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    int len = length(A);
    if (B >= len)
    {
        A = A->next;
        return A;
    }
    len = len - B - 1;
    ListNode* tail = A;
    while (len--)
        tail = tail->next;
    tail->next = tail->next->next;
    return A;

}
