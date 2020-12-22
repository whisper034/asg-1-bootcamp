#include<stdio.h> 
#include<stdlib.h> 

struct Node { 
	int data; 
	struct Node *next; 
}; 

void printMiddle(struct Node *head);
void push(struct Node **head_ref, int new_data);
void printList(struct Node *ptr);

int main() {
	struct Node *head = NULL;

	for (int i = 5; i > 0; i--) { 
		push(&head, i); 
		printList(head); 
		printMiddle(head); 
	} 

	return 0; 
}

void printMiddle(struct Node *head) { 
	struct Node *slow_ptr = head; 
	struct Node *fast_ptr = head; 

	if(head) { 
		while(fast_ptr && fast_ptr->next) { 
			fast_ptr = fast_ptr->next->next; 
			slow_ptr = slow_ptr->next; 
		} 
		printf("Middle element: [%d]\n\n", slow_ptr->data); 
	} 
}

void push(struct Node **head_ref, int new_data) { 
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *ptr) { 
	while(ptr) { 
		printf("%d->", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("NULL\n"); 
}