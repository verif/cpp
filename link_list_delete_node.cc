#include <stdio.h>

typedef struct ListNode {
  int val;
  ListNode * next;
  ListNode(int val_) {
    val = val_;
    next = NULL;
  }
} ListNode;

ListNode * delete_node (ListNode * head, int val) {
  if (!head) return NULL;
  ListNode * cur, * prev;
  ListNode dummy(0);
  dummy.next = head;
  cur = head;
  prev = &dummy;

  while (cur) {
    if (cur->val == val) {
      // found, remove it and adjust pointers on prev node
      prev->next = cur->next;
      delete cur;
      break;
    }
    prev = cur;
    cur = cur->next;
  }
  return dummy.next;
}

ListNode * delete_node_v2 (ListNode * head, int val) {
  ListNode * prev = NULL;
  ListNode * curr = head;

  while (curr) {
    if (curr->val == val)
      break;
    prev = curr;
    curr = curr->next;
  }

  if (curr) {
    if (prev == NULL) {
      head = curr->next; // adjust head pointer
    }
    else {
      prev->next = curr->next;
    }
    delete curr;
  }
  else {
    // didn't find match
  }
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
  head = delete_node_v2(head, 1);
  disp_list(head);
  return 0;
}
