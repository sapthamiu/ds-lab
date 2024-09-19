#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
typedef struct{
	char queue[MAX][100];
	int front;
	int rear;
}CQ;
void initialise(CQ *cq){
	cq->front = cq->rear = 0;
}
void insertcq(CQ *cq, char* str){
	if((cq->rear+1)%MAX == cq->front){
		printf("Queue is full");
		return;
	}
	cq->rear = (cq->rear+1)%MAX;
	strcpy(cq->queue[cq->rear],str);
	printf("%s inserted.", cq->queue[cq->rear]);
}

char* deletecq(CQ *cq){
	if(cq->front == cq->rear){
		printf("Queue is empty");
		return '\0';
	}
	cq->front = (cq->front+1)%MAX;
	return cq->queue[cq->front];
}

void displaycq(CQ *cq){
	if(cq->front == cq->rear){
		printf("Queue is empty");
		return;
	}
	printf("Queue elements: ");
	for(int i =(cq->front + 1)%MAX; i!=(cq->rear+1)%MAX; i= (i+1)% MAX)
		printf("%s ",cq->queue[i]);
	printf("\n");
}
void main(){
	CQ cq;
	initialise(&cq);
	int choice;
	char str[100];
	printf("--Menu--\n1. Insert\n2. Delete\n3. Display\n4. Exit");
	do{
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1: printf("Enter string to insert: ");
				scanf("%s", str);
				insertcq(&cq,str);
				break;
		case 2: printf("%s dequeued", deletecq(&cq));
				break;
		case 3: displaycq(&cq);
				break;
		case 4: exit(0);
		default: printf("Invalid choice");
		}
	}while(choice!=4);
}