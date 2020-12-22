//Source: gfg

#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 
  
struct Node { 
  int data; 
  struct Node *next; 
}; 
  
void MoveNode(struct Node **destRef, struct Node **sourceRef); 
  
struct Node *SortedMerge(struct Node *a, struct Node *b) { 
  struct Node dummy;
  struct Node *tail = &dummy;
  dummy.next = NULL; 
  while(1) { 
    if(!a) {
      tail->next = b; 
      break; 
    } 
    else if(!b) {
      tail->next = a; 
      break; 
    }
    if(a->data <= b->data) MoveNode(&(tail->next), &a); 
    else MoveNode(&(tail->next), &b); 
  
    tail = tail->next; 
  } 
  return(dummy.next); 
} 

void MoveNode(struct Node **destRef, struct Node **sourceRef);
void push(struct Node **head_ref, int new_data);
void printList(struct Node *node);

int main() {
  struct Node *res = NULL; 
  struct Node *a = NULL; 
  struct Node *b = NULL; 
  
  //sorted
  // a: 25->50->100,  b: 1->5->1000
  push(&a, 100); 
  push(&a, 50); 
  push(&a, 25);
  
  push(&b, 1000); 
  push(&b, 5); 
  push(&b, 1); 
  
  res = SortedMerge(a, b);
  
  printf("Merged Linked List is: \n"); 
  printList(res); 
  
  return 0; 
}

void printList(struct Node *node) { 
  while(node) { 
    printf("%d ", node->data); 
    node = node->next; 
  } 
}

void push(struct Node **head_ref, int new_data) {
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node)); 
  new_node->data  = new_data; 
  new_node->next = (*head_ref);
  (*head_ref)    = new_node; 
}

void MoveNode(struct Node **destRef, struct Node **sourceRef) { 
  struct Node *newNode = *sourceRef; 
  assert(newNode != NULL);
  *sourceRef = newNode->next;
  newNode->next = *destRef;
  *destRef = newNode; 
}