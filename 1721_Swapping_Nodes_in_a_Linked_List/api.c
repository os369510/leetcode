/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapNodes(struct ListNode* head, int k){
    int i = 0, len = 0, tmp = 0;
    struct ListNode *idx = head, *swap = NULL;
    while (idx) {
        if (i + 1 == k) {
            swap = idx;
        }
        len++;
        i++;
        idx = idx->next;
    }
    idx = head;
    for (i = 0; i < len - k; i++)
        idx = idx->next;
    tmp = swap->val;
    swap->val = idx->val;
    idx->val = tmp;
    return head;
}
