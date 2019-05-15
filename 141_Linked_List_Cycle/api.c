/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) return false;
    struct ListNode *tmp = head, *next, *previous = NULL;
    while (tmp)
    {
        next = tmp->next;
        tmp->next = previous;
        previous = tmp;
        tmp = next;
        if (tmp == head)
            return true;
    }
    return false;
}
