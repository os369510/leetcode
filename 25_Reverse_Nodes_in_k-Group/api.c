/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    int len = k - 1, swap = 0, first = 1, end = 0, ret_fix = 0, uncompleted = 0, done = 0;
    struct ListNode *sub_tail = NULL, *sub_head = NULL, *pre_sub_tail = NULL;
    struct ListNode *cursor = head, *previous = NULL, *next = NULL, *ret = head;
    if (!k || k == 1) return ret;
    while (cursor && cursor->next){
        while (len){
            if (!cursor)
            {
                if (!uncompleted && !done)
                    uncompleted = !uncompleted;
                break;
            }
            if (first)
            {
                first = !first;
                sub_tail = cursor;
                previous = cursor;
                cursor = cursor->next;
            }
            next = cursor->next;
            cursor->next = previous;
            previous = cursor;
            cursor = next;
            len--;
        }
        if (uncompleted && !done){
            first = !first;
            done = !done;
            len = k - 1;
            sub_tail->next = cursor;
            cursor = previous;
            continue;
        }
        sub_head = previous;
        if (pre_sub_tail)
            pre_sub_tail->next = sub_head;
        if (!ret_fix){
            ret = sub_head;
            ret_fix = !ret_fix;
        }
        sub_tail->next = cursor;
        pre_sub_tail = sub_tail;
        first = !first;
        len = k - 1;
    }
    return ret;
}
