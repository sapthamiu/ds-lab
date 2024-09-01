#include<stdio.h>
int lsearch(int [],int,int);
int main(){
	int a[100],i,m,ele;
	//int a[5] = {1,2,3,4,5};
	printf("Enter size of array: ");
	scanf("%d",&m);
	printf("Enter the elements: ");
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
		
	//int arrsize = &a[m]-&a[0];
        //printf("Array size is %d \n",arrsize);	
	printf("Enter element to search: ");
	scanf("%d",&ele);
	if(lsearch(a,m,ele)<0)
		printf("%d is not present in the array",ele);
	else printf("%d is present in position %d",ele,lsearch(a,m,ele));
	return 0;
}
int lsearch(int a[],int m,int ele)
{	
        int pos=-1;
	for(int i=0;i<m;i++)
		if(a[i]==ele)
			pos=i+1;
	return pos;
}


