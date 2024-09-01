/*Implement a C program to read, display and to find the product of two matrices using functions with suitable parameters. Note that the matrices should be created using dynamic memory allocation functions and the elements are accessed using array
dereferencing.*/
#include<stdio.h>
#include<stdlib.h>
void reader(int**,int,int);
void display(int**,int,int);
//int** makemat(int,int);
void product(int**, int**, int**, int, int, int, int);
int main(){
	int m,n,p,q;
	printf("Enter dimensions of first matrix: ");
	scanf("%d%d", &m,&n);
	printf("Enter dimensions of second matrix: ");
	scanf("%d%d", &p,&q);
	if(n!=p){
		printf("Incompatible");
		exit(0);
	}
	
	//int **a = makemat(m,n);
	int **a = (int**) malloc(m*sizeof(int));
	for(int i =0; i<m; i++)
		a[i] = (int*) malloc(n*sizeof(int));
	printf("\nEnter elements of first matrix: ");
	reader(a,m,n);
	/*for(int i =0; i<m;i++)
		for(int j = 0; j<n;j++)
			scanf("%d",&a[i][j]);
	*/
	//int **b = makemat(p,q);
	int **b = (int**) malloc(p*sizeof(int));
	for(int i =0; i<p; i++)
		b[i] = (int*) malloc(q*sizeof(int));
	printf("\nEnter elements of second matrix: ");
	
	reader(b,m,n);
	/*
	for(int i =0; i<p;i++)
		for(int j = 0; j<q;j++)
			scanf("%d",&b[i][j]);
	*/
	//printf("Test");
	//int **pro = makemat(m,q);
	int **pro = (int**) malloc(m*sizeof(int));
	for(int i =0; i<m; i++)
		pro[i] = (int*) malloc(q*sizeof(int));
	
	product(a,b,pro,m,n,p,q);
	printf("\nMatrix 1: ");
	display(a,m,n);
	
	printf("\nMatrix 2: ");
	display(b,p,q);
	
	printf("\nProduct: ");
	display(pro,m,q);
	return 0;
}

void reader(int** m, int r, int c){
	for(int i =0; i<r;i++)
		for(int j = 0; j<c;j++)
			scanf("%d",&m[i][j]);
}

void display(int** m, int r, int c){
	for(int i =0; i<r;i++){
		for(int j = 0; j<c; j++)
			printf("%d\t",*(*(m+i)+j));
		printf("\n");
	}
}
/*
int** makemat(int r, int c){
	int **m = (int**) malloc(r*sizeof(int*));
	for(int i =0; i<r; i++)
		m[i] = (int*) malloc(c*sizeof(int));
	return m;
}
*/
void product(int** m1, int** m2, int** pro, int r1, int c1, int r2, int c2){
	for(int i =0; i< r1;i++)
		for(int j=0;j<c2;j++){
			*(*(pro+i)+j) = 0;
			for(int k = 0; k< c1;k++)
				*(*(pro+i)+j)+= *(*(m1+i)+k) * *(*(m2+k)+j);
		}
}


