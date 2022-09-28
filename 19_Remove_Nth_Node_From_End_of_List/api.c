/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *arr[30];
    int i = 0, len = 0;
    struct ListNode *tmp = head;
    while (tmp) {
        arr[i] = tmp;
        tmp = tmp->next;
        ++len;
        ++i;
    }
    if (len == n)
        head = head->next;
    else {
        if (n == 1)
            arr[len - n - 1]->next = NULL;
        else
            arr[len - n - 1]->next = arr[len - n + 1];
    }
    return head;
}
