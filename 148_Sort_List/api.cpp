/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* _msort(ListNode *head, ListNode *tail, int len) {
        if (len <= 1) return head;
        int mid_idx = (len - 1) / 2;
        ListNode *mid = head, *midnext = head->next, *list1, *list2, *ret, *tmp;
        for (int i = 0; i < mid_idx; i++) {
            mid = mid->next;
            midnext = mid->next;
        }
        mid->next = NULL;
        list1 = _msort(head, mid, mid_idx + 1);
        list2 = _msort(midnext, tail, len - mid_idx - 1);
        if (list1->val <= list2->val)
            ret = list1;
        else {
            ret = list2;
            list2 = list1;
            list1 = ret;
        }
        list1 = list1->next;
        tmp = ret;
        while (list1 != NULL && list2 != NULL) {
            // perhaps list1 is minimum
            if (list1->val > list2->val) {
                tmp->next = list2;
                list2 = list2->next;
            }
            else {
                tmp->next = list1;
                list1 = list1->next;
            }
            tmp = tmp->next;
        }
        if (list1)
            tmp->next = list1;
        else if (list2)
            tmp->next = list2;
        return ret;
    }
    ListNode* sortList(ListNode* head) {
        ListNode *tmp = head, *tail;
        int size = 0;
        while (tmp) {
            if (tmp->next == NULL)
                tail = tmp;
            size++;
            tmp = tmp->next;
        }
        return _msort(head, tail, size);
    }
};
