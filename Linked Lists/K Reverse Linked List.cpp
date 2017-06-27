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


ListNode* Solution::reverseList(ListNode* A, int B) {
    int len = length(A);
    ListNode* prev = NULL;
    ListNode* head;
    ListNode* tail0 = NULL;
    ListNode* tail1 = NULL;
    int cnt = 0;
    int parity = 0;
    while (A != NULL)
    {
        int x = B;
        if (parity % 2 == 0)
            tail0 = A;
        else
            tail1 = A;
        while (x--)
        {
            if (cnt == B - 1)
                head = A;
            ListNode *temp = A->next;
            A->next = prev;
            prev = A;
            A = temp;
            cnt++;
        }
        parity++;
        if (parity == 1)
            tail0->next = NULL;
        else if (parity > 1 && parity % 2 == 0)
            tail0->next = prev;
        else if (parity > 1 && parity % 2 == 1)
            tail1->next = prev;
    }
    if ((len / B) % 2 && tail0)
        tail0->next = NULL;
    else if ((len / B) % 2 == 0 && tail1)
        tail1->next = NULL;
    return head;
}
