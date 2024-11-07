#include<stdio.h>
#include<stdlib.h>
#define MAX 4
typedef struct{
	int stack[MAX];
	int top;
}Stack;

void push(Stack* s, int x){
	s->stack[++(s->top)] = x;
}

void pop(Stack* s){
	return s->stack[(s->top)--];
}
void main(){
	Stack s1, s2;
	s1.top = s2.top = -1;
	int choice, ele;
	printf("1. Enqueue\n2. Dequeue\n3. Exit");
	while(1){
		printf("\nYour choice: ");
		scanf("%d", &choice);
		if(choice == 1){
			if(s1.top < MAX - 1){
				printf("Enter number to enqueue: ");
				scanf("%d", &ele);
				push(&s1, ele);
			}
			else printf("Queue is full");
		}
		else if(choice == 2){
			if(s2.top == -1){
				if(s1.top == -1)
					printf("Queue is empty");
				else while(s1.top != -1)
			}
		}
	}
}