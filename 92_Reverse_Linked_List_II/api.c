/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    if (m == n) return head;
    struct ListNode *rev_start, *before_start;
    struct ListNode *ret = head, *next, *previous;
    int idx = 0, reverse = 0;
    while (head){
        idx++;
        if (m == idx){
            before_start = previous;
            rev_start = head;
            reverse = 1;
        }
        if (!reverse){
            previous = head;
            head = head->next;
            continue;
        }
        next = head->next;
        head->next = previous;
        previous = head;
        if (n == idx){
            if (m != 1)
                before_start->next = head;
            rev_start->next = next;
            if (m == 1)
                ret = head;
            break;
        }
        head = next;
    }
    return ret;
}
