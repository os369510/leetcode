/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    int i = 0;
    struct ListNode _start = {0}, *p = NULL, *head = NULL;
    p = head = &_start;
    
    int min = 0, min_idx = 0, empty = 0;
    while (1) {
        for (i = 0, empty = 1; i < listsSize; i++) {
            if (!lists[i])
                continue;
            if (empty || min > lists[i]->val) {
                min = lists[i]->val;
                min_idx = i;
            }
            empty = 0;
        }
        if (empty)
            break;
        p->next = lists[min_idx];
        lists[min_idx] = lists[min_idx]->next;
        p = p->next;

    }
    return head->next;
}
