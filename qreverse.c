#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX];
int front = -1;
int rear = -1;

void enqueue(int ele){
	if(rear == MAX - 1){
		printf("Queue overflow");
		return;
	}
	if(front == -1)
		front++;
	q[++rear] = ele;
}

int isEmpty(){
	return front>rear || front == -1;
}

int dequeue(){
	if(isEmpty()){
		printf("Queue underflow");
		return -1;
	}
	int item = q[front++];
	if(front > rear)
		front = rear = -1;
	return item;
}

void reverse(){
	if(isEmpty()){
		//printf("Queue is empty");
		return;
	}
	int item = dequeue();
	reverse();
	enqueue(item);
}

void display(){
	if(isEmpty()){
		printf("Queue is empty");
		return;
	}
	printf("\nQueue elements: ");
	for(int i = front; i<=rear; i++)
		printf("%d  ", q[i]);
}
void main(){
	int choice, ele;
	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Reverse\n5. Exit");
	while(1){
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: printf("Enter the value to insert: ");
					scanf("%d", &ele);
					enqueue(ele);
					break;
			case 2: ele = dequeue();
					printf("%d dequeued", ele);
					break;
			case 3: display();
					break;
			case 4: reverse();
					printf("Queue reversed");
					break;
			case 5: printf("Exiting");
					exit(0);
			default: printf("Invalid choice");
		}
	}
}