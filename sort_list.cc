#include <stdio.h>

typedef struct ListNode {
    int val;
    ListNode * next;
    ListNode(int val_) : val(val_) {
      next = NULL;
    }
} ListNode;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode * fast = head->next;
        ListNode * slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * newHead = slow->next;
        slow->next = NULL;
        head = sortList(head);
        newHead = sortList(newHead);
        return mergeList(head, newHead);
    }
    
    ListNode * mergeList(ListNode * l1, ListNode * l2) {
        ListNode * c1 = l1;
        ListNode * c2 = l2;
        ListNode dummy(0);
        ListNode * prev = &dummy;
        while (c1 && c2) {
            if (c1->val < c2->val) {
                prev->next = c1;
                c1 = c1->next;
                prev = prev->next;
            }
            else {
                prev->next = c2;
                c2 = c2->next;
                prev = prev->next;
            }
        }
        if (c1)
            prev->next = c1;
        if (c2)
            prev->next = c2;
        return dummy.next;
    }
};


ListNode * init_list(int A[], int N) {
    ListNode dummy(0);
    ListNode * cur = &dummy;
    
    for (int i = 0; i < N; i++) {
        ListNode * newNode = new ListNode(A[i]);
        cur->next = newNode;
        cur = cur->next;
    }
    return dummy.next;
}

void disp_list (ListNode * head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main () {
    Solution sol;
    int A[] = {2, 1};
    ListNode * head = init_list(A, sizeof(A)/sizeof(int));
    disp_list(head);
    head = sol.sortList(head);
    disp_list(head);
}
