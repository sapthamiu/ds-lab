#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct Node* right;
	struct Node* left;
}NODE;
NODE* getNode(int data){
	NODE* newnode = malloc(sizeof(NODE));
	newnode->data = data;
	newnode->right = newnode->left = NULL;
	return newnode;
}
NODE* insertF(NODE* head, int data){
	NODE* newnode = getNode(data);
	if(head == NULL){
		return newnode;
	}
	newnode->right = head;
	head->left = newnode;
	head = newnode;
	printf("%d inserted at front", head->data);
	return head;
}
NODE* insertR(NODE* head, int data){
	NODE* newnode = getNode(data);
	if(head == NULL)
		return newnode;
	NODE* temp = head;
	while(temp->right != NULL)
		temp = temp->right;
	temp->right = newnode;
	newnode->left = temp;
	printf("%d inserted at rear", temp->data);
	return head;
}
NODE* deleteF(NODE* head){
	if(head == NULL){
		printf("Empty list");
		return NULL;
	}
	NODE* temp = head;
	if(head->right == NULL)
		head = NULL;
	else{
		head = head->right;
		head->left = NULL;
	}
	return temp;
}
NODE* deleteR(NODE* head){
	if(head == NULL){
		printf("Empty list");
		return NULL;
	}
	NODE* last = head;
	if(last->right == NULL)
		head = NULL;
	else{
		while(last->right != NULL)
			last = last->right;
		last->left->right = NULL;
	}
	return last;
}
