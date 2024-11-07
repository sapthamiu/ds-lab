#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}NODE;
NODE* insert(NODE* head, int data){
	NODE* newnode = malloc(sizeof(NODE));
	newnode->data = data;
	newnode->link = NULL;
	if(head == NULL)
		return newnode;
	NODE* temp = head;
	while(temp->link != NULL)
		temp = temp->link;
	temp->link = newnode;
	return head;
}
NODE* remdup(NODE* head){
	NODE* current = head;
	while(current != NULL && current->link != NULL){
		if(current->data == current->link->data){
			NODE*temp = current->link;
			current->link = current->link->link;
			free(temp);
		}
		else current = current->link;
	}
		return head;
}
void display(NODE* head){
	NODE* current = head;
	while(current != NULL){
		printf("%d\t", current->data);
		current = current->link;
	}
}
void main(){
	NODE* head = NULL;
	int choice, value;
	printf("--Menu")
}