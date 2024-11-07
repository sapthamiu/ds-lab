/*Perform UNION and INTERSECTION set operations on singly linked lists with and without header node.*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}NODE;
NODE* insert(NODE* head, int data){
	NODE* newnode = malloc(sizeof(NODE));
	newnode ->data = data;
	newnode->link = NULL;
	if(head == NULL)
		return newnode;
	if(head->link == NULL){
		head ->link = newnode;
		return head;
	}
	NODE* current = head;
	while(current->link != NULL)
		current = current ->link;
	current ->link = newnode;
	return head;
}
int isPresent(NODE* head, int data){
	NODE* current = head;
	if(head == NULL)
		return 0;
	while(current != NULL){
		if(current->data == data)
			return 1;
		current = current->link;
	}
	return 0;
}
NODE* unionL(NODE* head1, NODE* head2){
	NODE* unio = NULL;
	NODE* current = head1;
	while(current != NULL){
		unio = insert(unio, current->data);
		current = current->link;
	}
	current = head2;
	while(current != NULL){
		if(!isPresent(unio, current->data))
			unio = insert(unio, current->data);
		current = current->link;
	}
	return unio;
}
NODE* interL(NODE* head1, NODE* head2){
	NODE* inter = NULL;
	NODE* current = head1;
	while(current != NULL){
		if(isPresent(head2, current->data))
			inter = insert(inter, current->data);
		current = current->link;
	}
	return inter;
}
void display(NODE* head){
	NODE* current = head;
	if(head == NULL){
		printf("Empty list");
		return;
	}
	while(current != NULL){
		printf("%d\t", current->data);
		current = current->link;
	}
}
void main(){
	int choice, item;
	NODE *list1 = NULL;
	NODE* list2 = NULL;
	NODE* unio = NULL;
	NODE* inter = NULL;
	printf("--Menu--\n1. Insert into L1\n2. Insert into L2\n3. Display L1\n4. Display L2\n5. Union \n6. Intersection\n7. Exit");
	while(1){
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1: printf("Enter data: ");
				scanf("%d", &item);
				list1 = insert(list1, item);
				break;
		case 2: printf("Enter data: ");
				scanf("%d", &item);
				list2 = insert(list2, item);
				break;
		case 3: printf("List 1: ");
				display(list1);
				break;
		case 4: printf("List 2: ");
				display(list2);
				break;
		case 5: unio = unionL(list1, list2);
				printf("\nUnion: ");
				display(unio);
				break;
		case 6: inter = interL(list1, list2);
				printf("\nIntersection: ");
				display(inter);
				break;
		case 7: printf("\nExiting");
				exit(0);
		default: printf("Invalid  choice");
		}
	}
}