/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    ListNode *a, *b, *p1, *p2;
    ListNode* head = A;
    int cnt = 0;
    p1 = NULL;
    p2 = NULL;
    while (A != NULL)
    {
        cnt++;
        if (cnt == m - 1)
        {
            p1 = A;
            A = A->next;
        }
        else if (cnt == m)
        {
            a = A;
            b = a;
            A = A->next;
        }
        else if (cnt > m && cnt <= n)
        {
            ListNode* temp = A;
            A = A->next;
            temp->next = b;
            b = temp;
        }
        else if (cnt == n + 1)
        {
            p2 = A;
            A = A->next;
        }
        else
            A = A->next;
    }
    if (p1 != NULL)
        p1->next = b;
    a->next = p2;
    if (m == 1)
        return b;
    else
        return head;
}
