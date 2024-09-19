#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct{
	int stack[MAX];
	int top1;
	int top2;
}STACKS;
void push(STACKS *s, int stno, int ele){
	if(s->top1 < s->top2-1){
		if(stno == 1)
			s->stack[++(s->top1)]=ele;
		else if(stno ==2)
			s->stack[--(s->top2)]=ele;
		else printf("Invalid stack number.");
	}
	else printf("Stack Overflow. Cannot push.");
}
int pop(STACKS *s, int stno){
	if(stno == 1){
		if(s->top1 >=0)
			return s->stack[s->top1--];
		else {
			printf("Stack underflow. Cannot pop. ");
			return -1;
		}
	}
	else if(stno == 2){
		if(s->top2<MAX)
			return s->stack[s->top2--];
		else{
			printf("Stack overflow. Cannot pop. ");
			return -1;
		}
	}
	else {
		printf("Invalid stack no. ");
		return -1;
	}
}
void main(){
	STACKS s;
	s.top1 = -1;
	s.top2 = MAX;
	int stno, choice, n, ele;
	printf("Enter the number of stacks: ");
	scanf("%d", &n);
	if(n!=1 && n!=2){
		printf("Invalid no. of stacks");
		exit(0);
	}
	while(1){
		printf("\n1. Push\n2. Pop\n3. Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Stack no.: ");
				scanf("%d", &stno);
				if(stno>=1 && stno<=n){
					printf("Enter value to push: ");
					scanf("%d", &ele);	
					push(&s,stno,ele);
				}
				else printf("Invalid stack no.");
				break;
			case 2: printf("Stack no.: ");
				scanf("%d", &stno);
				if(stno>=1 && stno<=n){
					ele = pop(&s, stno);
					if(ele!=-1)
						printf("Popped value: %d",ele);
				}
				else printf("Invalid stack no.:");
				break;
			case 3: printf("Exiting");
				exit(0);
			default: printf("invalid choice");
		}
	}
}
