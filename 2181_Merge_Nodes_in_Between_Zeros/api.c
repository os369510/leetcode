/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeNodes(struct ListNode* head){
    struct ListNode *ret = NULL, *idx = NULL;
    int sum = 0;
    while (head) {
        if (head->val) {
            sum += head->val;
        }
        else if (sum) {
            head->val = sum;
            if (!ret)
                ret = idx = head;
            else {
                idx->next = head;
                idx = idx->next;
            }
            sum = 0;
        }
        head = head->next;
    }
    return ret;
}
