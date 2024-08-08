//To check whether a given String is Palindrome or not, using Recursion
#include<stdio.h>
#include<string.h>
int ispal(char*,char*);
int main(){
	char word[100],*first,*last;
	printf("Enter a word: ");
	scanf("%s",word);
	first= word;
	last= word+ strlen(word)-1;
	if(ispal(first,last)==1)
		printf("Palindrome\n");
	else printf("Not Palindrome\n");
	return 0;
}
int ispal(char* first, char* last){
	if(first>=last)
		return 1;
	if(*first!= *last)
		return 0;
	return(ispal(first+1,last-1));
}
