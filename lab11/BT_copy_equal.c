#include <stdio.h>
#include <stdlib.h>

// Define the structure of a Node in the Binary Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insertNode(struct Node* root, int data);
struct Node* copyTree(struct Node* root);
int areEqual(struct Node* root1, struct Node* root2);
void inorderTraversal(struct Node* root);

// Main function with menu
int main() {
    struct Node* root1 = NULL;
    struct Node* root2 = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into Tree 1\n");
        printf("2. Insert into Tree 2\n");
        printf("3. Copy Tree 1 to Tree 2\n");
        printf("4. Check if Tree 1 and Tree 2 are equal\n");
        printf("5. Display In-order Traversal of Tree 1\n");
        printf("6. Display In-order Traversal of Tree 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into Tree 1: ");
                scanf("%d", &data);
                root1 = insertNode(root1, data);
                printf("Inserted %d into Tree 1.\n", data);
                break;

            case 2:
                printf("Enter data to insert into Tree 2: ");
                scanf("%d", &data);
                root2 = insertNode(root2, data);
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
                inorderTraversal(root1);
                printf("\n");
                break;

            case 6:
                printf("In-order Traversal of Tree 2: ");
                inorderTraversal(root2);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a copy of a binary tree
struct Node* copyTree(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    struct Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

// Function to check if two binary trees are equal
int areEqual(struct Node* root1, struct Node* root2) {
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

// Function to perform in-order traversal of a binary tree
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}
