#include <stdio.h>

typedef struct ListNode {
  int val;
  ListNode * next;
  ListNode(int val_) {
    val = val_;
    next = NULL;
  }
} ListNode;

// insert node after target node
ListNode * insert_node (ListNode * head, int targetVal, int newVal) {
  if (!head) return NULL;
  ListNode * cur, * prev;
  ListNode dummy(0);
  dummy.next = head;
  cur = head;
  prev = &dummy;

  while (cur) {
    if (cur->val == targetVal) {
      // found, insert new node after it and adjust pointers on prev node
      ListNode * newNode = new ListNode(newVal);
      newNode->next = cur->next;
      cur->next = newNode;
      break;
    }
    prev = cur;
    cur = cur->next;
  }
  return dummy.next;
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
  int A[] = {1, 2, 3, 4};
  head = init_list(A, 4);
  disp_list(head);
  head = insert_node(head, 1, 5);
  disp_list(head);
  return 0;
}
