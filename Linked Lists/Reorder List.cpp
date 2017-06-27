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

ListNode* Solution::reorderList(ListNode* A) {
    int len = length(A);
    if (len <= 2)
        return A;
    ListNode *head, *prev;
    head = A;
    prev = A;
    int x = (len + 1) / 2;
    while (x--)
    {
        prev = A;
        A = A->next;
    }
    while (A != NULL)
    {
        ListNode* temp = A;
        A = A->next;
        temp->next = prev;
        prev = temp;
    }
    int l = 1, r = len - 1;
    ListNode *nodeL, *nodeR, *fakeHead;
    nodeL = head->next;
    fakeHead = head;
    nodeR = prev;
    while (l <= r)
    {
        ListNode* tempL;
        ListNode* tempR;
        tempL = nodeL;
        nodeL = nodeL->next;
        tempR = nodeR;
        nodeR = nodeR->next;
        fakeHead->next = tempR;
        fakeHead = fakeHead->next;
        fakeHead->next = tempL;
        fakeHead = fakeHead->next;
        l++;
        r--;
    }
    fakeHead->next = NULL;
    return head;
}
