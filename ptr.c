/*Write a C program to
a) Demonstrate passing pointers to a function.
b) Demonstrate Returning pointer from a function.
c) Using pointer to pointer.*/
#include<stdio.h>
#include<stdlib.h>
void pass(int*);
int* ret(int*);
void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d", &n);
	int *p = &n;
	printf("Original number: %d", *p);
	pass(p);
	printf("\nNumber after passing to function: %d",*p);
	printf("\nNumber after returning from function: %d", *(ret(p)));
	int **q = &p;
	printf("\nPointer to pointer: \n**q = %d\n*q = %p\nq = %p",**q,*q,q);
}
void pass(int* p){
	*p = *p * 2;
}
int* ret(int* p){
	*p+=6;
	return p;
}
