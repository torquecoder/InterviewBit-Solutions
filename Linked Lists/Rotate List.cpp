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

ListNode* Solution::rotateRight(ListNode* A, int B) {
    if (A == NULL)
        return A;
    int len = length(A);
    B = B % len;
    B = len - B;
    B = B % len;
    int x = B;
    ListNode *head, *temp;
    head = A;
    while (x--)
        head = head->next;
    ListNode* tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    temp = A;
    while (B--)
    {
        tail->next = temp;
        temp = temp->next;
        tail = tail->next;
    }
    tail->next = NULL;
    return head;
}
