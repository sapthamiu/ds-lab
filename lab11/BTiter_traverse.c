#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of a Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Iterative Pre-order Traversal (Root, Left, Right)
void iterativePreorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;

    // Push root node to stack
    stack[++top] = root;

    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        // Push right child first so that left is processed first
        if (node->right) {
            stack[++top] = node->right;
        }
        if (node->left) {
            stack[++top] = node->left;
        }
    }
}

// Iterative In-order Traversal (Left, Root, Right)
void iterativeInorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

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

// Iterative Post-order Traversal (Left, Right, Root) using Single Stack
void iterativePostorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    struct Node* lastVisited = NULL;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        if (current != NULL) {
            stack[++top] = current;
            current = current->left;
        } else {
            struct Node* peekNode = stack[top];
            if (peekNode->right != NULL && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                printf("%d ", peekNode->data);
                lastVisited = stack[top--];
            }
        }
    }
}

// Level-order Traversal (Breadth-First Search)
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* node = queue[front++];

        printf("%d ", node->data);

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

// Function to insert nodes in the Binary Tree (for testing purposes)
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Main function to test all the traversal methods
int main() {
    struct Node* root = NULL;

    int choice, value;

    while (1) {
        printf("\nBinary Tree Traversals Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Iterative Pre-order Traversal\n");
        printf("3. Iterative In-order Traversal\n");
        printf("4. Iterative Post-order Traversal\n");
        printf("5. Level-order Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                printf("Node inserted.\n");
                break;

            case 2:
                printf("Iterative Pre-order Traversal: ");
                iterativePreorder(root);
                printf("\n");
                break;

            case 3:
                printf("Iterative In-order Traversal: ");
                iterativeInorder(root);
                printf("\n");
                break;

            case 4:
                printf("Iterative Post-order Traversal: ");
                iterativePostorder(root);
                printf("\n");
                break;

            case 5:
                printf("Level-order Traversal: ");
                levelOrderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
