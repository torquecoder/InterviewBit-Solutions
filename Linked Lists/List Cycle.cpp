/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *slow_p = A, *fast_p = A;
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            slow_p = A;
            while (slow_p != fast_p)
            {
                slow_p = slow_p->next;
                fast_p = fast_p->next;
            }
            return fast_p; 
        }
    }
    return NULL;
}

