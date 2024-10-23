#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
typedef struct{
	char stack[MAX];
	int top;
}STACK;
void push(STACK *s, char ele){
	s->stack[++(s->top)] = ele;
}
char pop(STACK *s){
	return s->stack[s->top--];
}
int precedence(char opr){
	switch(opr){
		case '+': 
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		default:  return 0;
	}
}
void reverse(char *exp){
	int n = strlen(exp);
	for(int i = 0; i<n/2; i++){
		 char temp = exp[i];
		 exp[i] = exp[n-1-i];
		 exp[n-1-i] = temp;
	 }
}
void convert(char *infix){
	reverse(infix);
	int n = strlen(infix);
	//reverse brackets
	for(int i=0; i<n; i++){
	if(infix[i]=='(')
		infix[i] = ')';
	else if(infix[i]==')')
		infix[i] = '(';
	}
	STACK s;
	s.top = -1;
	char prefix[MAX];
	int k = 0;
	for(int i =0; infix[i]!='\0';i++){
		if(isalnum(infix[i])) //push the operands
			prefix[k++]=infix[i];
		else if(infix[i]=='(') //push the open bracket
			push(&s,infix[i]);
		else if(infix[i]==')'){
			while(s.top!=-1 && s.stack[s.top]!='(') //pop until met with open bracket
				prefix[k++]=pop(&s);
			pop(&s);//pop the open bracket
		}
		else{
			while(s.top!=-1 && precedence(s.stack[s.top])>precedence(infix[i])) //pop greater precedence operators before pushing an operator
				prefix[k++]=pop(&s);
			push(&s,infix[i]);
		}
	}
	while(s.top!=-1)
		prefix[k++]=pop(&s); //pop remaining elements
	prefix[k]='\0';
	reverse(prefix); //convert from postfix to prefix
	printf("Prefix expression: %s", prefix);
}
void main(){
	char infix[MAX];
	printf("Enter infix: ");
	scanf("%s", infix);
	convert(infix);
}

	
