/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reorderList(struct ListNode* head){
    struct ListNode *cur = head;
    struct ListNode **arr = NULL;
    int count = 0, e = 0, len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
    arr = calloc(len, sizeof(struct ListNode*));
    cur = head;
    while (cur) {
        if (count <= (len - 1) / 2)
            arr[count * 2] = cur;
        else {
            if (len % 2)
                arr[len - (e + 1) * 2] = cur;
            else
                arr[len - 1 - e * 2] = cur;
            e++;
        }
        cur = cur->next;
        count++;
    }
    int i = 0;
    for (i = 0; i < len - 1; i++)
        arr[i]->next = arr[i + 1];
    arr[i]->next = NULL;
    return arr[0];
}
