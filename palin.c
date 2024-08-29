//Determine whether a given string is palindrome or not using stack
#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct{
	char stack[MAX];
	int top;
}STACK;
void push(STACK* s, char item);
char pop(STACK* s);
int isPalin(char str[]);
void main(){
	char str[MAX];
	printf("Enter a string: ");
	scanf("%s",str);
	if(isPalin(str))
		printf("%s is a palindrome", str);
	else
		printf("%s is not a palindrome", str);
}
void push(STACK *s, char item){
	s->top++;
	s->stack[s->top]= item;
}
char pop(STACK *s){
	return s->stack[s->top--];
}
int isPalin(char str[]){
	STACK s;
	s.top = -1;
	int l = strlen(str);
	int i;
	for(i =0; i<l/2;i++)
		push(&s,str[i]);
	if(l%2!=0)
		i++;
	while(str[i]!='\0'){
		if(str[i]!=pop(&s)||s.top==-1)
			return 0;
		i++;
	}
	return 1;
}

