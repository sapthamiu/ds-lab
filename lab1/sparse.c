/*Check if matrix is sparse matrix*/
#include<stdio.h>
int ifsparse(int[][100],int,int);
int main(){
	int a[100][100],i,j,m,n,count=0;
	printf("Enter the dimensions of the matrix: ");
	scanf("%d%d",&m,&n);
	printf("Enter the elements: ");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	if(ifsparse(a,m,n)==1)
		printf("Matrix is sparse");
	else printf("Matrix is not sparse");
	return 0;
}
int ifsparse(int a[][100],int m,int n){
	int count=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]==0)
				count++;
	if(count>m*n/2)
		return 1;
	else return 0;
}
