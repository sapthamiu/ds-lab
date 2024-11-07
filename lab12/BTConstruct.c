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

// Helper function to find an element in the array
int findIndex(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Element not found
}

// Recursive function to construct the binary tree
struct Node* buildTree(int pre[], int post[], int* preIndex, int postStart, int postEnd, int n) {
    // Base case
    if (*preIndex >= n || postStart > postEnd) {
        return NULL;
    }

    // The first element in pre[] is always root
    struct Node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    // If the tree has only one node, return it
    if (postStart == postEnd || *preIndex >= n) {
        return root;
    }

    // Find the next element in pre[] in post[]
    int postIndex = findIndex(post, n, pre[*preIndex]);

    // Recursively construct the left and right subtrees
    if (postIndex <= postEnd) {
        root->left = buildTree(pre, post, preIndex, postStart, postIndex, n);
        root->right = buildTree(pre, post, preIndex, postIndex + 1, postEnd - 1, n);
    }

    return root;
}

// Utility function to print in-order traversal of the binary tree
void printInOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

// Driver function
int main() {
    int n;

    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);

    int pre[100], post[100];
    printf("Enter the pre-order traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    printf("Enter the post-order traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }

    int preIndex = 0;
    struct Node* root = buildTree(pre, post, &preIndex, 0, n - 1, n);

    printf("In-order traversal of the constructed tree:\n");
    printInOrder(root);
    printf("\n");

    return 0;
}

/*
Pre-order: 1 2 4 5 3 6 7
Post-order: 4 5 2 6 7 3 1
Inorder of tree: 4 2 5 1 6 3 7
*/