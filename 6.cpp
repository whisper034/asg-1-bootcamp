#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

static void reverse(struct Node **head_ref) {
	struct Node *prev = NULL;
	struct Node *current = *head_ref;
	struct Node *next = NULL;
	while(current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void push(struct Node **head_ref, int new_data);
void printList(struct Node *head);

int main() {
	struct Node *head = NULL;

  //sorted
  // 3->10->25->100
	push(&head, 100);
	push(&head, 25);
	push(&head, 10);
	push(&head, 3);

	printf("Before:\n");
	printList(head);
	reverse(&head);
	printf("\nAfter:\n");
	printList(head);
  puts("");
}

void push(struct Node **head_ref, int new_data) {
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head) {
	struct Node *temp = head;
	while(temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}