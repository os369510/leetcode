/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int ret = 0;
    while (head) {
        ret *= 2;
        ret += head->val;
        head = head->next;
    }
    return ret;
}
