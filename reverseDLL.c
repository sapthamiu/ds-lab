#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
	char word[100];
	struct Node* left;
	struct Node* right;
}NODE;
NODE* getNode(char* word){
	NODE* newnode = malloc(sizeof(NODE));
	strcpy(newnode->word, word);
	newnode->left = newnode->right = NULL;
	return newnode;
}
NODE* append(NODE* head, char* word){
	NODE* newnode = getNode(word);
	NODE* last = head;
	if(head == NULL)
		return newnode;
	while(last->right != NULL)
		last = last->right;
	last->right = newnode;
	newnode->left = last;
	return head;
}
NODE* reverse(NODE* head){
	NODE* current = head;
	NODE* temp = NULL;
	while(current != NULL){
		temp = current->left;
		current->left = current->right;
		current->right = temp;
		current = current->left;
	}
	if(temp != NULL)
		head = temp->left;
	return head;
}
void display(NODE* head){
	if(head == NULL){
		printf("List is empty");
		return;
	}
	while(head != NULL){
		printf("%s ", head->word);
		head = head->right;
	}
}
void main(){
	NODE* head = NULL;
	int choice;
	char word[100];
	printf("--Menu--\n1. Append a word\n2. Print list\n3. Reverse the list\n4. Exit");
	while(1){
		printf("\nYour choice: ");
		scanf("%d", &choice);
		switch(choice){
		case 1: printf("Enter the word to append: ");
				scanf("%s", word);
				head = append(head, word);
				printf("Word appended");
				break;
		case 2: printf("Current list: ");
				display(head);
				break;
		case 3: head = reverse(head);
				printf("List reversed");
				break;
		case 4: printf("Exiting");
				exit(0);
		default: printf("Invalid choice");
		}
	}
}