//To copy one string to another using Recursion.
#include<stdio.h>
#include<string.h>
void copy(char*,char*);
int main(){
	char s[100],d[100];
	printf("Enter the string to be copied: ");
	gets(s);
	copy(s,d);
	printf("Copied string: %s\n",d);
	return 0;
}
void copy(char* s, char* d){
	if(*s=='\0')
		return;
	*d= *s;
	copy(s+1,d+1);
}
	
