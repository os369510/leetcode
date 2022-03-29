/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int pairSum(struct ListNode* head){
    int count = 0, max = 0, i = 0;
    struct ListNode *c = head, *prev = NULL, *next = NULL;
    while (c) {
        c = c->next;
        count++;
    }
    c = head;
    while (c) {
        if (i++ < count / 2) {
            next = c->next;
            c->next = prev;
            prev = c;
            c = next;
        }
        else {
            if (max < c->val + prev->val) {
                max = c->val + prev->val;
            }
            c = c->next;
            prev = prev->next;
        }
    }
    return max;
}
