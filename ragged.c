/*Write a C program to implement a ragged array dynamically.*/
#include<stdio.h>
#include<stdlib.h>
void main(){
	int row, col, i,j;
	int **matrix;
	printf("Enter no. of rows:");
	scanf("%d",&row);
	matrix = (int**) calloc(row+1, sizeof(int*));
	for(i=0; i<row;i++){
		printf("Enter size of row %d",i+1);
		scanf("%d",&col);
		matrix[i] = (int*) calloc(col+1, sizeof(int));
		printf("\nENter %d row elements", i+1);
		for(j=1;j<=col;j++)
			scanf("%d", &table[i][j]);
		table[i][0] = col;
		printf("size of row number [%d] = %d", i+1, table[i][0]);
	}
	table[i] = NULL;
	for(i=0;i<row;i++){
	printf("displaying %d row elements\n", i+1);
	for(j=0;j<=*table[i];j++)
		printf("%5d", matrix[i][j]); 
