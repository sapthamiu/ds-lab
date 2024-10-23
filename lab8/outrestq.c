#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

typedef struct{
	char deque[MAX][100];
	int front;
	int rear;
}Deque;

void insertF(Deque*, char*);
void insertR(Deque*, char*);
char* deleteF(Deque*);
void display(Deque*);

void main(){
	Deque dq;
	dq.front = dq.rear = 0;
	//dq.deque = (char* )malloc(MAX * sizeof(char));
	int choice;
	char str[100];
	printf("1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Display\n5. Exit");
	while(1){
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1: //insertf
				printf("Enter string to insert at front: ");
				scanf("%s", &str);
				insertF(&dq, str);
				break;
		case 2: //insertr
				printf("Enter string to insert at rear: ");
				scanf("%s", str);
				insertR(&dq, str);
				break;
		case 3: //deleteF
				strcpy(str,deleteF(&dq));
				if(str)
					printf("%s deleted", str);
				break;
		case 4: //display
				display(&dq);
				break;
		case 5: printf("Exiting");
				exit(0);
		default: printf("Invalid choice");
		}
	}
}

void insertF(Deque* dq, char* str){
	if((dq->front - 1 + MAX) % MAX == dq->rear){
		printf("Deque overflow");
		return;
	}
	dq->front = (dq->front - 1 + MAX) % MAX;
	strcpy(dq-> deque[(dq->front + 1) % MAX], str);
}

void insertR(Deque* dq, char* str){
	if((dq->rear+1) % MAX == dq->front){
		printf("Deque overflow");
		return;
	}
	dq->rear = (dq->rear + 1) % MAX;
	strcpy(dq->deque[dq->rear], str);
}

char* deleteF(Deque* dq){
	if(dq->front == dq->rear){
		printf("Deque is empty");
		return'\0';
	}
	dq->front = (dq->front+1)%MAX;
	return dq->deque[dq->front];
}

void display(Deque* dq){
	if(dq->front == dq->rear){
		printf("Deque is empty");
		return;
	}
	printf("Deque elements: ");
	for(int i = (dq->front+1) % MAX; i!= (dq->rear + 1) % MAX; i = (i+1) % MAX)
		printf("%s \t", dq->deque[i]);	
}