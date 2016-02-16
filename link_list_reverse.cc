#include <stdio.h>

typedef struct ListNode {
  int val;
  ListNode * next;
  ListNode(int val_) {
    val = val_;
    next = NULL;
  }
} ListNode;

ListNode * reverse_list(ListNode * head) {
  ListNode * curr = head;
  ListNode * prev = NULL;
  ListNode * next = NULL;

  while (curr) {
    next = curr->next;
    curr->next = prev;

    // move to next
    prev = curr;
    curr = next;
  }
  return prev;
}

// helper function
ListNode * init_list(int A[], int N) {
  if (N == 0) return NULL;
  ListNode * head = new ListNode(A[0]);
  ListNode * p = head;
  for (int i = 1; i < N; i++) {
    p->next = new ListNode(A[i]);
    p = p->next;
  }
  return head;
}

void disp_list(ListNode * head) {
  while (head) {
    printf("%d ", head->val);
    head = head->next;
  }
  printf("\n");
}

int main () {
  ListNode * head;
  int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  head = init_list(A, sizeof(A)/sizeof(int));
  disp_list(head);
  head = reverse_list(head);
  disp_list(head);

  int B[] = {1};
  head = init_list(B, sizeof(B)/sizeof(int));
  disp_list(head);
  head = reverse_list(head);
  disp_list(head);
  return 0;
}
