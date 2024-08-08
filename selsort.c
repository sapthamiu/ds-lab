//To implement selection sort using recursion
#include<stdio.h>
int minindex(int[],int,int);
void selsort(int [], int, int);
int main(){
	int a[100],n;
	printf("Enter size of the array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	selsort(a,n,0);
	printf("Sorted array: ");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
int minindex(int a[],int index,int last){
	if(index==last)
		return index;
	int k= minindex(a, index+1,last);
	if(a[k]< a[index])
		return k;
	else return index;
}
void selsort(int a[],int n,int i){
	if(i==n)
		return;
	int k= minindex(a,i,n-1);
	if(k!=i)
	{
		int temp= a[i];
		a[i]=a[k];
		a[k]=temp;
	}
	selsort(a,n,i+1);
}

