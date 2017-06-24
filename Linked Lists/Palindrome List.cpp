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


int Solution::lPalin(ListNode* A) {

    int n = length(A);
    int curr_len = 0;
    ListNode *mid = A, *prev = NULL;
    while (curr_len != n / 2)
    {
        prev = mid;
        mid = mid->next;
        curr_len++;
    }
    if (n % 2)
    {
        prev = mid;
        mid = mid->next;
    }

    while (mid != NULL)
    {
        ListNode* temp = mid->next;
        mid->next = prev;
        prev = mid;
        mid = temp;
    }

    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (A->val != prev->val)
            return 0;
        else
        {
            A = A->next;
            prev = prev->next;
            l++;
            r--;
        }
    }
    return 1;

}
