/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) return false;
    struct ListNode *tmp = head;
    struct ListNode *tmp2 = head->next;
    while (tmp && tmp2 && tmp2->next)
    {
        tmp = tmp->next;
        tmp2 = tmp2->next->next;

        if (tmp == tmp2)
            return true;
    }
    return false;
}
