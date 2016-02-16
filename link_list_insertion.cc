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
  // try to find the target value in existing nodes and insert new node
  // after that. If not found, insert at the end of list.
  ListNode * curr = head;
  ListNode * prev = NULL;
  int found = 0;

  while (curr && found == 0) {
    if (curr->val == targetVal)
      found = 1;
    // move to next
    prev = curr;
    curr = curr->next;
  }

  ListNode * newNode = new ListNode(newVal);
  prev->next = newNode;
  newNode->next = curr;
  if (head == NULL)
    head = newNode;

  return head;
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
