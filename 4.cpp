#include<stdio.h> 
#include<stdlib.h> 

struct Node { 
	int data; 
	struct Node *next; 
};

void removeDuplicates(struct Node *head);
void push(struct Node **head_ref, int new_data);
void printList(struct Node *node);

int main() {
	struct Node *head = NULL;

  // sorted
	push(&head, 500); 
	push(&head, 100); 
	push(&head, 100); 
	push(&head, 100); 
	push(&head, 25); 
	push(&head, 25);									 

	puts("\nBefore:"); 
	printList(head); 

	removeDuplicates(head); 

	puts("\nAfter:");		 
	printList(head);			 
	
	return 0; 
} 

void removeDuplicates(struct Node *head) { 
	struct Node *current = head;
	struct Node *next_next;
	if(!current) return;

	while(current->next) { 
    if(current->data == current->next->data) {
      next_next = current->next->next; 
      free(current->next); 
      current->next = next_next; 
    }
    else current = current->next; 
	} 
}

void push(struct Node **head_ref, int new_data) { 
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)); 
	new_node->data = new_data;
	new_node->next = (*head_ref);	 
	(*head_ref) = new_node; 
}

void printList(struct Node *node) { 
	while(node) { 
    printf("%d ", node->data); 
    node = node->next;
	} 
}