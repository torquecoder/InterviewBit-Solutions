/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0), *node1, *node2;
    node1 = dummy1;
    node2 = dummy2;
    while (A) 
    {
        if (A->val < B) 
        {
            node1->next = A;
            node1 = node1->next;
        } 
        else 
        {
            node2->next = A;
            node2 = node2->next;
        }
        A = A->next;
    }
    node2->next = NULL;
    node1->next = dummy2->next;
    return dummy1->next;
}

