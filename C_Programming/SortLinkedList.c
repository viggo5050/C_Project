

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>


typedef struct node {
	int data;
	struct node * next;
}Node;

Node* addSortedLinkedList(int data,Node*head){
	Node* new_node = (Node*) malloc(sizeof(Node));
	assert(new_node != NULL);
	if (head ==NULL){
		new_node->data = data;
		new_node->next = NULL;
		return new_node;
	}
	if (data<head->data){
		new_node->data = data;
		new_node->next = head;
		head = new_node;
		return head;
	}
	Node*current_ptr = head;
	Node*next_ptr = head->next;

	while ((current_ptr->next != NULL) && (current_ptr->next->data < data)){
		next_ptr = next_ptr->next;
		current_ptr = current_ptr->next;
	}
	new_node->data = data;
	new_node->next = next_ptr;
	current_ptr->next = new_node;
	return head;

}

void printLinkedList(Node* ptr){
	while(ptr != NULL){
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}

int main(void){

	int arr[5];
	for (int i =0;i<5;i++){
		scanf("%d",&(arr[i]));
	}
	Node* head = NULL;
	Node* next = NULL;

	for (int i =0;i<5;i++){
		head = addSortedLinkedList(arr[i],head);

	}
	printLinkedList(head);
}


















