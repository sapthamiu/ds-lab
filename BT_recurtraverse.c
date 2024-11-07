#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct node{
	int data;
	struct node* left, *right;
}NODE;

NODE* createNode(int data){
	NODE* newnode = malloc(sizeof(NODE));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

NODE* createBT(NODE* root, int data){
	NODE *newnode;
    NODE *child;
    NODE *parent;
    char direction[20];//starting from root
    int i;

    newnode = createNode(data);
    if (root == NULL)
        return newnode;
  
    printf("Enter the directions to insert the data (L for left, R for right):");
    scanf("%s", direction);

    child = NULL;
    parent = root;

    for (i = 0; i < strlen(direction); i++) {
        child = parent;

        if (toupper(direction[i]) == 'L'){
            parent = parent->left;
       //     printf("left");
        }
        else if (toupper(direction[i]) == 'R'){
            parent = parent->right;
      //      printf("right");
        }

        if (parent == NULL && i != strlen(direction) - 1) {
            printf("Invalid direction. No node found at given path.\n");
            return root;
        }
    }
    if (toupper(direction[i - 1]) == 'L'){
        child->left = newnode;
       // printf("left inserted");
    }
    else{
        child->right = newnode;
       // printf("right inserted");
    }
    return root;
}

void inorder(NODE* root){
	if(root == NULL) return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void preorder(NODE* root){
	if(root == NULL) return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(NODE* root){
	if(root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

void main() {
    NODE* root = NULL;
    int choice, value;

    printf("---Menu---\n1. Insert Node\n2. In-order Traversal\n3. Pre-order Traversal\n4. Post-order Traversal\n5. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = createBT(root, value);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}