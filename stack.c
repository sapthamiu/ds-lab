/*Implement a menu driven program to define a stack of characters. Include push, pop
and display functions. Also include functions for checking error conditions such
as underflow and overflow (ref. figure 1) by defining isEmpty and isFull functions.
Use these function in push, pop and display functions appropriately. Use type defined
structure to define a STACK containing a character array and an integer top. Do not
use global variables.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct{
	char stack[MAX];
	int top;
}STACK;
void push(STACK*, char);
char pop(STACK*);
void display(STACK*);
int isFull(STACK*);
int isEmpty(STACK*);
void main(){
	STACK s;
	char item;
	int choice;
	s.top = -1;
	printf("---STACK MENU---\n1:Push\n2:Pop\n3:Display\n4:Exit");
	do{
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1: //push
			printf("Enter item to push: ");
			scanf(" %c",&item);
			push(&s,item);
			break;
		case 2: //pop
			printf("%c popped",pop(&s));
			break;
		case 3: //display
			display(&s);
			break;
		case 4: printf("Exiting. Thank you");
			break;
		}
	}while(choice!=4);
}
void push(STACK *s, char item){
	if(isFull(s)){
		printf("Stack Overflow. Cannot push");
		return;
	}
	s->top++;
	s->stack[s->top] = item;
	printf("%c pushed.",item);
}
char pop(STACK *s){
	if(isEmpty(s)){
		printf("Stack underflow. Cannot pop");
		return'\0';
	}
	return s->stack[s->top--];
}
void display(STACK *s){
	for(int i = s->top; i>=0; i--)
		printf("%c \n",s->stack[i]);
}
int isFull(STACK *s){
	return s->top==MAX-1;	
}
int isEmpty(STACK *s){
	return s->top==-1;
}


