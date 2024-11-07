#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node in a binary tree (level order insertion)
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    
    struct Node* queue[100]; // Array-based queue for level order insertion
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front < rear) {
        struct Node* temp = queue[front++];
        
        // Check left child
        if (temp->left == NULL) {
            temp->left = newNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }
        
        // Check right child
        if (temp->right == NULL) {
            temp->right = newNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }
    return root;
}

// Recursive function to print all ancestors of a key in a binary tree
int printAncestors(struct Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    
    if (root->data == key) {
        return 1;
    }
    
    if (printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->data);
        return 1;
    }
    
    return 0;
}

// Driver function to build the tree and find ancestors of the given key
int main() {
    struct Node* root = NULL;
    int n, i, data, key;
    
    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);
    
    printf("Enter the values of the nodes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    
    printf("Enter the key to find its ancestors: ");
    scanf("%d", &key);
    
    printf("Ancestors of %d: ", key);
    if (!printAncestors(root, key)) {
        printf("Key not found in the tree.");
    }
    printf("\n");
    
    return 0;
}
