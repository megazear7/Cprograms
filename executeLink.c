#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int val;
	struct node *next;
}node;

// Requires: head is a pointer to a pointer to a correctly formatted LinkedList Struct
// Requires: amount is an integer value greater than 0
// Ensures: head is no a pointer to struct which is the first element in a linked list of size amount
// 			and each elements val fields increase by 1, starting from 1
createList(node **head, int amount){
	node *handle = *head;
	handle->val = 1;
	int i;
	for(i = 0; i < amount-1; i++){	
		node *temp;
		temp = (node*)malloc(sizeof(node));
		temp->val = i + 2;
		handle->next = temp;

		handle = handle->next;
	}	
}

// Requires: head is a pointer to a correctly foramtted LinkedList struct that ends in a null pointer
// Ensures: output to stdin will be the value of each element in order until a null pointer is reached
printList(node **head){
	node *handle = *head;
	int i;
	while(handle){
		printf("%d ", handle->val);
		handle = handle->next;
	}
	printf("\n");
}

// Requires head is a pointer to a pointer to a correctly formatted LinkedList struct that does not wrap
//			head is the first element in the list
// Ensures: the list represented by head now wraps (i.e. its a circle)
makeWrap(node **head){
	int i;
	node *handle =  *head;
	while(handle->next){
		handle = handle->next;
	}
	handle->next = *head;
}


// Requires head is a pointer to a pointer to a correctly formatted LinkedList struct that does wrap
//			head is the first element in the list
// Ensures: the list represented by head now does not wrap (i.e. its not a circle)
makeUnwrap(node **head){
	node *handle =  *head;
	while(handle->next != *head){
		handle = handle->next;
	}
	handle->next = NULL;
}

// Requires: head is a pointer to a pointer to a correctly formatted LinkedList struct that wraps
// Requires: location > 0
// Ensures: the list represented by head will be the same except that the element that 
// 			is at position location (with respect to head) is removed and head now points to the position after the previusly removed item
removeElement(node **head, int location){
	int i;
	node *handle = *head;
	for(i = 0; i < location-1; i++){
		handle = handle->next;
	}
	handle->next = handle->next->next;	
	*head = handle->next;
}

// Requires: head is a pointer to a pointer to a correctly formatted LinkedList struct that wraps
// Ensures: only one element in the list will remain, and it will be the one coorosponding to the
//			execute game
playExecute(node **head, int size){
	node *handle = *head;
	int i;
	for(i = 0; i < size-1; i++){
		removeElement(&handle, i + 1);
	}
}

int main() {
	node *head;
	head = (node*)malloc(sizeof(node));
	
	int size;
	printf("How many people are playing the execute game? ");
	scanf("%d",&size);

	createList(&head, size);
	printList(&head);
	makeWrap(&head);
	//removeElement(&head, 1);
	//removeElement(&head, 2);
	//removeElement(&head, 3);
	//removeElement(&head, 4);
	//removeElement(&head, 5);
	//removeElement(&head, 6);
	//removeElement(&head, 7);
	//removeElement(&head, 8);
	
	int i;
	for(i = 0; i < size-1; i++){
		removeElement(&head, i + 1);
	}
	
	makeUnwrap(&head);
	printList(&head);
	return 0;
}
