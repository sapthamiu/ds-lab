//Simulate the working of Tower of Hanoi for n disks. Print the number of moves.
#include<stdio.h>
void hantow(int,char,char,char,int*);
int main(){
	int n,count=0;
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	hantow(n,'A','C','B',&count);
	printf("Total number of moves: %d\n",count);
	return 0;
}
void hantow(int n, char src, char dest, char temp, int* count){
	if(n==1){
		printf("Move disk 1 from %c to %c\n",src,dest);
		(*count)++;
		return;
	}
	//move n-1 disks from src to temp
	hantow(n-1, src, temp, dest, count);
	//nth disk
	printf("Move disk %d from %c to %c\n",n,src, dest);
	(*count)++;
	//move n-1 disks from temp to dest
	hantow(n-1, temp,dest,src,count);
}

