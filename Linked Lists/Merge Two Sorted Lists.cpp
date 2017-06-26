/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    if (A == NULL && B == NULL)
        return NULL;
    ListNode* a = A;
    ListNode* b = B;
    ListNode *head, *tail;
    int flag = 0;
    while (a != NULL && b != NULL)
    {
        ListNode* temp;
        if (a -> val <= b -> val)
        {
            temp = a;
            a = a->next;
        }
        else
        {
            temp = b;
            b = b->next;
        }
        if (!flag)
        {
            head = temp;
            flag = 1;
            tail = head;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
    while (a != NULL)
    {
        if (!flag)
        {
            head = a;
            flag = 1;
            tail = head;
        }
        else
        {
            tail->next = a;
            tail = tail->next;
        }
        a = a->next;
    }
    while (b != NULL)
    {
        if (!flag)
        {
            head = b;
            flag = 1;
            tail = head;
        }
        else
        {
            tail->next = b;
            tail = tail->next;
        }
        b = b->next;
    }
    tail->next = NULL;
    return head;
}
