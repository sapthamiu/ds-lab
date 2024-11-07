#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}NODE;

NODE* createNode(int data) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
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
        }
        else if (toupper(direction[i]) == 'R'){
            parent = parent->right;
        }

        if (parent == NULL && i != strlen(direction) - 1) {
            printf("Invalid direction. No node found at given path.\n");
            return root;
        }
    }
    if (toupper(direction[i - 1]) == 'L'){
        child->left = newnode;
    }
    else{
        child->right = newnode;
    }
    return root;
}

NODE* copyTree(NODE* root) {
    if (root == NULL) {
        return NULL;
    }

    NODE* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

int areEqual(NODE* root1, NODE* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1; // Both are NULL, so they are equal
    }
    if (root1 == NULL || root2 == NULL) {
        return 0; // One of them is NULL, they are not equal
    }
    return (root1->data == root2->data) &&
           areEqual(root1->left, root2->left) &&
           areEqual(root1->right, root2->right);
}

void inorder(NODE* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main() {
    NODE* root1 = NULL;
    NODE* root2 = NULL;
    int choice, data;

        printf("\nMenu:\n");
        printf("1. Insert into Tree 1\n");
        printf("2. Insert into Tree 2\n");
        printf("3. Copy Tree 1 to Tree 2\n");
        printf("4. Check if Tree 1 and Tree 2 are equal\n");
        printf("5. Display In-order Traversal of Tree 1\n");
        printf("6. Display In-order Traversal of Tree 2\n");
        printf("7. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into Tree 1: ");
                scanf("%d", &data);
                root1 = createBT(root1, data);
                printf("Inserted %d into Tree 1.\n", data);
                break;

            case 2:
                printf("Enter data to insert into Tree 2: ");
                scanf("%d", &data);
                root2 = createBT(root2, data);
                printf("Inserted %d into Tree 2.\n", data);
                break;

            case 3:
                root2 = copyTree(root1);
                printf("Tree 1 has been copied to Tree 2.\n");
                break;

            case 4:
                if (areEqual(root1, root2)) {
                    printf("Tree 1 and Tree 2 are equal.\n");
                } else {
                    printf("Tree 1 and Tree 2 are not equal.\n");
                }
                break;

            case 5:
                printf("In-order Traversal of Tree 1: ");
                inorder(root1);
                printf("\n");
                break;

            case 6:
                printf("In-order Traversal of Tree 2: ");
                inorder(root2);
                printf("\n");
                break;

            case 7:
                printf("Exiting\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}