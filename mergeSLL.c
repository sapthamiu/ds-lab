#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node* link;
}NODE;
NODE* insert(NODE* head, int data){
	NODE* newnode = malloc(sizeof(NODE));
	newnode->data = data;
	newnode->link = NULL;
	if(head == NULL)	
		return newnode;
	NODE* current = head;
	while(current->link != NULL && current->data <data)
		current = current->link;
	//newnode->link = current->link;
	current->link = newnode;
	return head;	
}
void display(NODE* head){
	NODE* temp = NULL;
	while(temp != NULL){
		printf("%d\t", temp->data);
		temp = temp->link;
	}
}
NODE* merge(NODE* list1, NODE* list2){
	NODE* merged = NULL;
	while(list1 != NULL && list2 != NULL){
		if(list1->data == list2->data){
			merged = insert (merged, list1->data);
			list1 = list1->link;
			list2 = list2->link;
		}
		if(list1->data > list2->data){
			merged = insert(merged, list2->data);
			list2 = list2->link;
		}
		if(list1->data < list2->data){
			merged = insert(merged, list1->data);
			list1 = list1->link;
		}
	}
	while(list1 != NULL){
		merged = insert(merged, list1->data);
		list1 = list1->link;
	}
	while(list2 != NULL){
		merged = insert(merged, list2->data);
		list2 = list2->link;
	}
	return merged;
}
void main(){
	int n1, n2, item;
	NODE* classA = NULL, *classB = NULL;
	printf("Enter the no. of students in class A and class B: ");
	scanf("%d%d", &n1, &n2);
	printf("Enter the heights of students in class A: ");
	for(int i = 0; i<n1; i++){
		scanf("%d", &item);
		classA = insert(classA, item);
	}
	printf("Enter the heights of students in class B: ");
	for(int i = 0; i<n2; i++){
		scanf("%d", &item);
		classB = insert(classB, item);
	}
	NODE* merged = merge(classA, classB);
	printf("\nClass A: ");
	display(classA);
	printf("\nClass B: ");
	display(classB);
	printf("\nMerged class: ");
	display(merged);
}