/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* next = NULL, *previous = NULL;
    if (!head || !head->next) return head;
    while (head){
        next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;
}
