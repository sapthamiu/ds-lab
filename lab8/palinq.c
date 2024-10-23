#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char dq[MAX];
int front = -1;
int rear = -1;
void insertR(char item){
	if(rear == MAX - 1){
		printf("Deque overflow0");
		return;
	}
	if(front == -1 && rear == -1)
		front = 0;
	dq[++rear] = item;
}
char deleteF(){
	char item;
	if(front == -1){
		printf("Deque underflow");
		return '\0';
	}
	item = dq[front++];
	if(front > rear)
		front = rear = -1;
	return item;
}
char deleteR(){
	char item;
	if(front == -1){
		printf("Deque underflow");
		return '\0';
	}
	item = dq[rear--];
	if(front > rear)
		front = rear = -1;
	return item;
}
int ispalin(char* str){
	for(int i = 0; str[i]!= '\0'; i++)
		insertR(tolower(str[i]));
	while(front != -1 && rear != -1 && front<rear)
		if(deleteF()!= deleteR())
			return 0;
	return 1;
}
void main(){
	char str[MAX];
	printf("Enter a string: ");
	scanf("%s", str);
	if(ispalin(str))
		printf("Palindrome");
	else printf("Not palindrome");
}