#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}node;

// Requires: head is a pointer to a pointer to a correctly formatted LinkedList Struct
// Requires: amount is an integer value greater than 0
// Ensures: head is no a pointer to the first element in a linked list of size amount
// 			and each elements val fields increase by 1, starting from 1
createList(node **head, int amount){
	node *handle = *head;
	int i;
	for(i = 0; i < amount; i++){	
		node *temp;
		temp = (node*)malloc(sizeof(node));
		temp->val = i + 1;
		handle->next = temp;

		handle = handle->next;
	}	
}

// Requires: head is a pointer to a correctly foramtted LinkedList struct
// Ensures: output to stdin will be the value of each element in order until a null pointer is reached
printList(node *head){
	node *handle = head;
	int i;
	while(handle){
		printf("%d ", handle->val);
		handle = handle->next;
	}
	printf("\n");
}

int main() {
	node *head;
	head = (node*)malloc(sizeof(node));
	
	createList(&head, 9);
	printList(head->next);
	return 0;
}
