#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1;
int rear = -1;
void insert(int);
int delete();
void display();
void main(){
	int choice, ele;
	printf("1. Insert\n2. Delete\n3. Display\n4. Exit");
	while(1){
		printf("\nYour choice: ");
		scanf("%d",&choice);
		switch(choice){
		case 1: //insert
				printf("Enter element to insert: ");
				scanf("%d",&ele);
				insert(ele);
				break;
		case 2: //delete
				ele = delete();
				if(ele!=-1)
					printf("%d deleted", ele);
				break;
		case 3: //display
				display();
				break;
		case 4: printf("Exiting");
				exit(0);
		default: printf("Invalid choice.");
		}
	}
}
void insert(int ele){
	if(rear>=MAX-1){
		printf("Queue overflow");
		return;
	}
	if(front == -1 && rear == -1){
		front++;
		queue[++rear] = ele;
	}
	else{
		int i;
		for(i = rear; (i>=front && queue[i]>ele); i--)
			queue[i+1] = queue[i];
		queue[i+1] = ele;
		rear++;
	}
}
int delete(){
	if(front==-1 || front>rear){
		printf("Queue underflow");
		return -1;
	}
	int ele = queue[front];
	front++;
	if(front>rear)
		front = rear = -1;
	return ele;
}
void display(){
	if(front == -1 || front>rear){
		printf("Queue is empty");
		return;
	}
	printf("Queue elements: ");
	for(int i = front; i<=rear; i++)
		printf("%d  ", queue[i]);
}