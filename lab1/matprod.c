/*Find product of two matrices*/
#include<stdio.h>
#include<stdlib.h>
void product(int [][100],int [][100],int, int, int, int);
int main(){
	int a[100][100],b[100][100],m,n,p,q,i,j;
	printf("Enter dimensions of first array: ");
	scanf("%d%d",&m,&n);
	printf("Enter dimensions of second array: ");
	scanf("%d%d",&p,&q);
	if(n!=p)
	{	printf("Not compatible.");
		exit(0);
	}
	printf("Enter the elements of first matrix: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter elements of second matrix: ");
	for(i=0;i<p;i++)
		for(j=0;j<q;j++)
			scanf("%d",&b[i][j]);
	product(a,b,m,n,p,q);
	return 0;
}
void product(int a[][100],int b[][100],int m,int n,int p,int q){
	int prod[100][100],i,j,k;
	for(i=0;i<m;i++)
		for(j=0;j<q;j++)
		{	prod[i][j]=0;
			for(k=0;k<n;k++)
				prod[i][j]+=(a[i][k]*b[k][j]);
		}
	printf("Product matrix: ");
	for(i=0;i<m;i++)
	{	for(j=0;j<q;j++)
			printf("%d\t",prod[i][j]);
		printf("\n");
	}
}

