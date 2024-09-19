#include<stdio.h>
#include<stdlib.h>
#define N 5
typedef struct{
	int arr[N];
	int front1, front2, rear1, rear2;
}CQs;
void initialise(CQs *dq){
	dq->rear1 = dq->front1 = 0;
	dq->rear2 = dq->front2 = (N/2 + 1);
}
void insertcq(CQs *dq, int qno, int ele){
	if(qno == 1){
		if((dq->rear1 + 1)%(N/2+1)==dq->front1){
			printf("Q1 is full.");
			return;
		}
		dq->rear1 = (dq->rear1+1) % (N/2 + 1);
		dq->arr[dq->rear1] = ele;
	}
	else if(qno == 2){
		if((dq->rear2 + 1)%(N - (N/2 + 1)) + (N/2 + 1) == dq->front2){
			printf("Q2 is full.");
			return;
		}
		dq->rear2 = (dq->rear2+1) % (N - (N/2 + 1)) + (N/2 + 1);
		dq->arr[dq->rear2] = ele;
	}
	else printf("Enter valid queue number.");
}
int deletecq(CQs *dq, int qno){
	if(qno == 1){
		if(dq->front1 == dq->rear1){
			printf("Q1 is empty.");
			return -1;
		}
		dq-> front1 = (dq->front1 + 1) % (N/2 + 1);
		return dq->arr[dq->front1];
	}
	else if(qno == 2){
		if(dq->front2 == dq->rear2){
			printf("Q2 is empty.");
			return -1;
		}
		dq->front2 = (dq->front2 + 1) % (N - (N/2 + 1)) + (N/2 + 1);
		return dq ->arr[dq->front2];
	}
	else{
		printf("Enter valid queue number.");
		return -1;
	}
}
void display(CQs *dq, int qno){
	if(qno == 1){
		if(dq->front1 == dq->rear1){
			printf("Q1 is empty.");
			return;
		}
		printf("Queue elements: ");
		for(int i =(dq->front1 + 1)%(N/2 + 1); i!=(dq->rear1+1) % (N/2 + 1); i= (i+1)% (N/2 + 1))
			printf("%s ",dq->arr[i]);
		printf("\n");
	}
	else if(qno == 2){
		if(dq->front2 == dq->rear2){
			printf("Q2 is empty.");
			return;
		}
		printf("Queue elements: ");
		for(int i =(dq->front2 + 1) % (N - (N/2 + 1)) + (N/2 + 1); i!=(dq->rear2+1) % (N - (N/2 + 1)) + (N/2 + 1); i= (i+1) % (N - (N/2 + 1)) + (N/2 + 1))
			printf("%s ",dq->arr[i]);
		printf("\n");
	}
	else printf("Enter valid queue number. ");
}
void main(){
	CQs dq;
	initialise(&dq);
	int choice, ele;
	printf("--Menu--\n1. Insert to Q1\n2. Insert to Q2\n3. Delete from Q1\n4. Delete from Q2\n5. Display Q1\n6. Display Q2\n7. Exit");
	do{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1: printf("Enter value to enqueue: ");
				scanf("%d",&ele);
				insertcq(&dq, 1, ele);
				break;
		case 2: printf("Enter value to enqueue: ");
				scanf("%d",&ele);
				insertcq(&dq, 2, ele);
				break;
		case 3: printf("%d dequeued.", deletecq(&dq, 1));
				break;
		case 4: printf("%d dequeued.", deletecq(&dq, 2));
				break;
		case 5: display(&dq, 1);
				break;
		case 6: display(&dq, 2);
				break;
		case 7: exit(0);
		default: printf("Enter valid input");
		}
	}while(choice!=7);
}