#include<stdio.h>
#define MAX 100
typedef struct{
	int data[MAX];
	int front;
	int rear;
}Q;
void initialise(Q *q){
	q->front = 0;
	q->rear = -1;
}
void enqueue(Q *q, int ele){
	if(q->rear < MAX 
}