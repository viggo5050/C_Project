


#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Node;

Node* addNode(int data,Node*next){


	Node* node  = (Node*)malloc(sizeof(Node));
	assert(node != NULL);
	node->data = data;
	node->next = next;
	return node;

}
void printLinkedlist(Node* ptr){
	while (ptr!=NULL){
		printf("%d\n",ptr->data );
		ptr = ptr->next;
	}

}

void freeLinkedlist(Node*ptr){
	while (ptr != NULL){
		Node* ptr_next = ptr->next;
		free(ptr);
		ptr = ptr_next;
	}
}
int main(void){

	int arr[3];
	for (int i = 0;i<3;i++){
		scanf("%d",&(arr[i]));
	}
	Node* head ;
	Node* previous = NULL;

	for (int i = 0;i<3;i++){
		head = addNode(arr[i],previous);
		previous = head;
	}
	printLinkedlist(head);
	freeLinkedlist(head);

}




