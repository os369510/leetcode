/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    if (!head) return head;
    int len = 0, back = 0, decrease = 0;
    struct ListNode *next, *previous = NULL;
    while (head){
        len++;
        next = head->next;
        head->next = previous;
        if (!next && !back) {
            if (len % 2)
                decrease = len / 2 + 1;
            else
                decrease = len / 2;
            len = 0;
            back = 1;
            previous = NULL;
            continue;
        }
        previous = head;
        if (back && decrease == len)
            break;
        head = next;
    }
    return head;
}
