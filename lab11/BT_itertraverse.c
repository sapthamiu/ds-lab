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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(NODE* root) {
    if (root == NULL) return;

    NODE* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        NODE* node = stack[top--];
        printf("%d ", node->data);

        if (node->right)
            stack[++top] = node->right;
        if (node->left)
            stack[++top] = node->left;
    }
}

void inorder(NODE* root) {
    if (root == NULL) return;

    NODE* stack[100];
    int top = -1;
    NODE* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void postorder(NODE* root) {
    if (root == NULL) return;

    NODE* stack[100];
    int top = -1;
    NODE* lastVisited = NULL;
    NODE* current = root;

    while (current != NULL || top >= 0) {
        if (current != NULL) {
            stack[++top] = current;
            current = current->left;
        } else {
            NODE* temp = stack[top];
            if (temp->right != NULL && lastVisited != temp->right) {
                current = temp->right;
            } else {
                printf("%d ", temp->data);
                lastVisited = stack[top--];
            }
        }
    }
}

void levelorder(NODE* root) {
    if (root == NULL) return;

    NODE* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        NODE* node = queue[front++];

        printf("%d ", node->data);

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
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


void main() {
    NODE* root = NULL;

    int choice, value;

        printf("\nBinary Tree Traversals Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Iterative Pre-order Traversal\n");
        printf("3. Iterative In-order Traversal\n");
        printf("4. Iterative Post-order Traversal\n");
        printf("5. Level-order Traversal\n");
        printf("6. Exit\n");
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
                printf("Iterative Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Iterative In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Iterative Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Level-order Traversal: ");
                levelorder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}