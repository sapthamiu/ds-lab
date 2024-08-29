/*Given an array arr with n elements and a number k, k<n. The task is to delete k
elements which are smaller than next element (i.e., we delete arr[i] if arr[i] <
arr[i+1]) or become smaller than next because next element is deleted.*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct{
	int stack[MAX];
	int top;
}STACK;
void push(STACK* s,int item){
	s->top++;
	s->stack[s->top]=item;
}
int pop(STACK*s){
	return s->stack[s->top--];
}
void delele(int arr[], int n, int k){
	STACK s;
	s.top = -1;
	for(int i = 0; i<n; i++){
		while(s.top>=0 && s.stack[s.top]<arr[i] && k>0){
			s.top--;
			k--;
		}
		push(&s,arr[i]);
	}
	while(s.top!=-1)
		printf("%d ",pop(&s));//prints in descending order. Use for loop for ascending order
	printf("\n");
}
void main(){
	int arr[MAX], n, k;
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i = 0; i<n; i++)
		scanf("%d",&arr[i]);
	printf("Enter the no. of elements to delete: ");
	scanf("%d",&k);
	if(k>=n)
		printf("k should be less than n");
	delele(arr,n,k);
}
	
