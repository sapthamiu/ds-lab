#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* createBinTree(struct Node* root, int item) {
    struct Node *temp;  // Node to be inserted
    struct Node *prev;  // Parent node
    struct Node *cur;   // Current node
    char direction[20]; // String to take directions
    int i;

    temp = createNode(item);

    if (root == NULL) {
        return temp;  // If the tree is empty, return the new node as the root
    }

    printf("Enter the directions to insert the item (L for left, R for right):\n");
    scanf("%s", direction);

    prev = NULL;
    cur = root;

    // Traverse the tree based on the given direction string
    for (i = 0; i < strlen(direction); i++) {
        prev = cur;

        if (toupper(direction[i]) == 'L') {
            cur = cur->left;
        } else if (toupper(direction[i]) == 'R') {
            cur = cur->right;
        }

        // If we reach a NULL position before the end of the string, break
        if (cur == NULL && i != strlen(direction) - 1) {
            printf("Invalid direction. No node found at given path.\n");
            return root;
        }
    }

    // Insert the node as either a left or right child
    if (toupper(direction[i - 1]) == 'L') {
        prev->left = temp;
    } else {
        prev->right = temp;
    }

    return root;
}
// Recursive In-order Traversal (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Recursive Pre-order Traversal (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Recursive Post-order Traversal (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

// Main function - Menu-driven approach
int main() {
    struct Node* root = NULL;
    int choice, value;

    
        printf("\nBinary Tree Menu:\n");
        printf("1. Insert Node\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Exit\n");
    while (1) {
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
                printf("In-order Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;

            case 3:
                printf("Pre-order Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Post-order Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
