/*Write a function Smallest to find the smallest element in an array using pointer.
Create a dynamically allocated array and read the values from keyboard in main.
Display the result in the main function.*/
#include<stdio.h>
#include<stdlib.h>
int* smallest(int*, int);
void main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int* a = (int*) malloc(n*sizeof(int));
	printf("Enter the elements: ");
	for(int i = 0; i<n ; i++)
		scanf("%d",&a[i]);
	int *small = smallest(a, n);
	printf("Smallest element: %d", *small);
}
int* smallest(int *a, int n){
	int *s = a;
	for(int i = 0;i<n;i++)
		if(*s > *(a+i))
			*s = *(a+i);
	return s;
}
