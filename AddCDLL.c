#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}NODE;
NODE* getNode(int data){
	NODE* newnode = malloc(sizeof(NODE));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}
NODE* getHeader(){
	NODE* header = malloc(sizeof(NODE));
	header->data = 0;
	header->left = header->right = header;
	return header;
}
NODE* insertR(NODE* header, int data){
	NODE* newnode = getNode(data);
	if(header->right == header){
		header->right = newnode;
		header->left = newnode;
		newnode->right = header;
		newnode->left = header;
	}
	else{
		NODE* last = header->left;
		last->right = newnode;
		newnode->right = header;
		newnode->left = last;
		header->left = newnode;
	}
	header->data++; //increment no. of digits
	return header;
}
void display(NODE* header){
	if(header->right == header){
		printf("Empty list");
		return;
	}
	NODE* temp = header->left;
	printf("Number: ");
	while(temp != header){
		printf("%d", temp->data);
		temp = temp->left;
	}
}
NODE* addnos(NODE* header1, NODE* header2){
	NODE* result = getHeader();
	NODE* temp1 = header1->right;
	NODE* temp2 = header2->right;
	int carry = 0;
	while(temp1 != header1 || temp2 != header2 || carry != 0){
		int digit1 = (temp1 != header1)? temp1->data : 0;
		int digit2 = (temp2 != header2)? temp2->data : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result = insertR(result, sum % 10);
		if(temp1 != header1)
			temp1 = temp1->right;
		if(temp2 != header2)
			temp2 = temp2->right;
	}
	return result;
}
void main(){
	int num1, num2;
	printf("Enter the first long no.: ");
	scanf("%d", &num1);
	printf("Enter the second long no.: ");
	scanf("%d", &num2);
	NODE* header1 = getHeader();
	while(num1 != 0){
		header1 = insertR(header1, num1 % 10);
		num1 /= 10;
	}
	NODE* header2 = getHeader();
	while(num2 != 0){
		header2 = insertR(header2, num2 %10);
		num2 /= 10;
	}
	printf("\nFirst ");
	display(header1);
	printf("\nDigits in first no.: %d", header1->data);
	printf("\nSecond ");
	display(header2);
	printf("\nDigits in second no.: %d", header2->data);
	NODE* result = addnos(header1, header2);
	printf("\nResult ");
	display(result);
	printf("\nDigits in result: %d", result->data);
}