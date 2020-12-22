#include <stdio.h>
#include <stdlib.h>

struct Node { 
	int data; 
	struct Node *next; 
}; 

void printNthFromLast(struct Node *head, int n);
void push(struct Node **head_ref, int new_data);

int main() {
	struct Node *head = NULL;

  // 700->23->6->34
	push(&head, 34); 
	push(&head, 6); 
	push(&head, 23); 
	push(&head, 700); 

  int index;
  scanf("%d", &index);
	printNthFromLast(head, index); 
	return 0; 
}

void printNthFromLast(struct Node *head, int n) { 
	int len = 0;
	struct Node *temp = head;
	while(temp) {
		temp = temp->next;
		len++;
	}

	if(len < n) return;
	temp = head; 

	for(int i = 1; i < len - n + 1; i++) 
		temp = temp->next; 

	printf("%d\n", temp->data); 

	return; 
}

void push(struct Node **head_ref, int new_data) { 
	struct Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node; 
}