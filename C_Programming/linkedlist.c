

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define Length 2

struct Node { 
    int data; 
    struct Node* next; 
}; 

void printlinkedlist(struct Node *node){
	for(;node !=NULL;node = node->next)
		printf("%d\n",node->data );
}

int main() {

    struct Node* head = NULL; 
    struct Node* second = NULL; 
    struct Node* third = NULL; 
  
    // allocate 3 nodes in the heap 
    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
    head->data = 1; // assign data in first node 
    head->next = second;
    second->data = 2; 
  
    // Link second node with the third node 
    second->next = third; 
    third->data = 3; // assign data to third node 
    third->next = NULL; 
    // struct Node* ptr = head;
    while (head != NULL)
    	printf("%d\n",head->data );
    	head = head->next;

    // struct Node* ptr = head;
    // printlinkedlist(head);

    // while (head != NULL){
    // 	printf("val is%d\n" ,head->data);
    // 	head = head->next;
    // 	}
}
















