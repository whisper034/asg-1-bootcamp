#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};
 
void push(struct Node **head_ref, int new_data);
int detectLoop(struct Node *list);
 
int main() {
  struct Node *head = NULL;
 
  push(&head, 300);
  push(&head, 255);
  push(&head, 400);
  push(&head, 1000);
 
  // loop
  head->next->next->next->next = head;
 
  (detectLoop(head)) ? puts("Loop found") : puts("No Loop");
  return 0;
}

void push(struct Node** head_ref, int new_data) {
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int detectLoop(struct Node *list) {
  struct Node *slow_p = list, *fast_p = list;
  while(slow_p && fast_p && fast_p->next) {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;
    if (slow_p == fast_p) {
      return 1;
    }
  }
  return 0;
}