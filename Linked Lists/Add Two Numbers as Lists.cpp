/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *currA = A;
    ListNode *currB = B;
    int sum = 0, carry = 0;
    if (!A)
        return B;
    if (!B)
        return A;
    while (currA->next && currB->next)
    {
       sum = currA->val + currB->val + carry;
       carry = sum / 10;
       currA->val = sum % 10;
       currA = currA->next;
       currB = currB->next;
    }
    sum = currA->val + currB->val + carry;
    carry = sum / 10;
    currA->val = sum % 10;
    if (!(currA->next))
       currA->next = currB->next;
    while (currA->next)
    {
        currA = currA->next;
        sum = currA->val + carry;
        carry = sum / 10;
        currA->val = sum % 10;
    }
    if (carry > 0)
    {
        ListNode *l = new ListNode(carry);
        currA->next = l;
        l->next = NULL;
    }
    return A;
}
