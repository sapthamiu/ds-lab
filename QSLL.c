#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}NODE;
typedef struct queue{
	NODE* front;
	NODE* rear;
}Q;
void insertR(Q* q, int data){
	NODE* newnode = malloc(sizeof(NODE));
	newnode->data = data;
	newnode->link = NULL;
	if(q->front==NULL)
		q->front = q->rear = newnode;
	else{
		q->rear->link = newnode;
		q->rear = newnode;
	}
}
void deleteF(Q*q){
	if(q->front == NULL){
		printf("Queue underflow");
		return;
	}
	NODE* temp = q->front;
	printf("%d deleted", *(q->front));
	q->front = q->front->link;
}
void display(Q*q){
	if(q->front == NULL){
		printf("Empty queue");
		return;
	}
	NODE* current = q->front;
	printf("Queue elements: ");
	while(current!=q->rear->link){
		printf("%d\t", current->data);
		current = current->link;
	}
}
void main(){
	int choice, item;
	Q queue;
	queue.front = queue.rear = NULL;
	printf("--Menu--\n1. Insert\n2. Delete\n3. Display\n4. Exit");
	while(1){
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1: //insert
				printf("Enter element to insert: ");
				scanf("%d", &item);
				insertR(&queue, item);
				break;
		case 2: //delete
				deleteF(&queue);
				break;
		case 3: //display
				display(&queue);
				break;
		case 4: printf("Exiting");
				exit(0);
		default: printf("Invalid choice");
		}
	}
}