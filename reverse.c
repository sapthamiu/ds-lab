/*Write a function Reverse to reverse the elements of an integer array using pointer.
Access the elements of the array using dereference operator. Read the values from
the keyboard in main function. Display the result in the main function.*/
#include<stdio.h>
#include<stdlib.h>
void reverse(int*, int);
int main(){
	int n;
	printf("Enter size of array: ");
	scanf("%d",&n);
	int* a = (int*) malloc(n * sizeof(int));
	printf("Enter the elements: ");
	for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Array: ");
	for(int i = 0;i < n;i++)
		printf("%d\t",a[i]);
	printf("\nReversed array: ");
	reverse(a, n);
	for(int i = 0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}
void reverse(int* a, int n){
	for(int i = 0;i<n/2;i++){
		int temp = a[i];
		a[i] = a[n-1-i];
		a[n-1-i]= temp;
	}
}
