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

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int n = length(A);
    int m = length(B);
    int d = abs(n - m);
    if (n >= m)
    {
        while (d--)
            A = A->next;
    }
    else
    {
        while (d--)
            B = B->next;
    }
    ListNode* ans = NULL;
    while (A != NULL && B != NULL && A != B)
    {
        A = A->next;
        B = B->next;
    }
    ans = A;
    return ans;
}
