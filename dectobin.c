//Convert a given decimal number to binary using stack.
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct{
	int stack[MAX];
	int top;
}STACK;
void push(STACK*,int);
int pop(STACK*);
void dectobin(int);
void main(){
	int n;
	printf("Enter the decimal number: ");
	scanf("%d", &n);
	printf("\nBinary equivalent: ");
	dectobin(n);
}
void push(STACK *s, int n){
	s->top++;
	s->stack[s->top]=n;
}
int pop(STACK *s){
	return s->stack[s->top--];
}
void dectobin(int n){	
	STACK s;
	s.top = -1;
	while(n>0){
		int rem = n%2;
		push(&s,rem);
		n/=2;
	}
	while(s.top!=-1)
		printf("%d",pop(&s));
	printf("\n");
}
	
	
