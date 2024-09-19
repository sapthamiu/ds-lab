#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#define MAX 100
typedef struct{
	int top;
	float stack[MAX];
}STACK;
void push(STACK *s, int ele){
	s->stack[++(s->top)]=ele;
}
float pop(STACK *s){
	return s->stack[s->top--];
}
float evaluate(char *exp){
	STACK s;
	s.top = -1;
	int n = strlen(exp);
	for(int i = n-1; i>=0; i--){
		if(isdigit(exp[i]))
			push(&s, exp[i]-'0');
		else{
			float op1, op2;
			op1 = pop(&s);
			op2 = pop(&s);
			switch(exp[i]){
				case '+': push(&s, op1+op2);
					  break;
				case '-': push(&s,op1-op2);
					  break;
				case '*': push(&s, op1*op2);
				 	  break;
			 	case '/': push(&s, op1/op2);
			 		  break;
		 		case '^': push(&s, pow(op1,op2));
		 			  break;
 			        default:  printf("Invalid operator");
		        }
	        }
        }
        return pop(&s);
}
void main(){
	char expression[MAX];
	printf("Enter the prefix expression: ");
	scanf("%s", expression);
	printf("Result: %.2f", evaluate(expression));
}

