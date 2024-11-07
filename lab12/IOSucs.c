#include <stdio.h>
#include <stdlib.h>

// Definition of a tree node
typedef struct node {
    int info;
    struct node* lchild;
    struct node* rchild;
} NODE;

// Function prototypes
NODE* getnode();
NODE* insertBST(NODE* root, int item);
NODE* findNode(NODE* root, int item);
NODE* inOrderSuccessor(NODE* root, NODE* target);
void inOrderTraversal(NODE* root);

// Function to allocate a new node
NODE* getnode() {
    NODE* x = (NODE*)malloc(sizeof(NODE));
    if (x == NULL) {
        printf("Running out of memory\n");
        return NULL;
    }
    return x;
}

// Function to insert a new node in the BST
NODE* insertBST(NODE* root, int item) {
    NODE *cur, *parent, *newnode = getnode();
    if (newnode == NULL) return root;  // Memory allocation failed

    newnode->info = item;
    newnode->lchild = newnode->rchild = NULL;

    if (root == NULL) {
        root = newnode;
        return root;
    }

    cur = root;
    while (cur != NULL && (cur->info != item)) {
        parent = cur;
        if (item < cur->info)
            cur = cur->lchild;
        else if (item > cur->info)
            cur = cur->rchild;
        else {
            printf("No duplicates allowed\n");
            free(newnode);
            return root;
        }
    }

    if (item < parent->info)
        parent->lchild = newnode;
    else
        parent->rchild = newnode;

    return root;
}

// Function to find a node with a specific value in the BST
NODE* findNode(NODE* root, int item) {
    while (root != NULL) {
        if (item < root->info)
            root = root->lchild;
        else if (item > root->info)
            root = root->rchild;
        else
            return root;
    }
    return NULL;  // Node not found
}

// Function to find the in-order successor of a given node
NODE* inOrderSuccessor(NODE* root, NODE* target) {
    if (target == NULL) return NULL;

    // Case 1: If the node has a right subtree
    if (target->rchild != NULL) {
        NODE* temp = target->rchild;
        while (temp->lchild != NULL) {
            temp = temp->lchild;
        }
        return temp;
    }

    // Case 2: No right subtree - start from root to find the successor
    NODE* successor = NULL;
    NODE* current = root;
    while (current != NULL) {
        if (target->info < current->info) {
            successor = current;  // Update successor when going left
            current = current->lchild;
        } else if (target->info > current->info) {
            current = current->rchild;
        } else {
            break;
        }
    }

    return successor;
}

// Function for in-order traversal of the BST
void inOrderTraversal(NODE* root) {
    if (root != NULL) {
        inOrderTraversal(root->lchild);
        printf("%d ", root->info);
        inOrderTraversal(root->rchild);
    }
}

// Main function to display the menu and handle user choices
int main() {
    NODE* root = NULL;
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Find in-order successor of a node\n");
        printf("3. Display in-order traversal of the BST\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &data);
                root = insertBST(root, data);
                printf("Node %d inserted.\n", data);
                break;

            case 2:
                printf("Enter the value to find its in-order successor: ");
                scanf("%d", &data);
                NODE* target = findNode(root, data);
                if (target != NULL) {
                    NODE* successor = inOrderSuccessor(root, target);
                    if (successor != NULL) {
                        printf("In-order successor of %d is %d\n", target->info, successor->info);
                    } else {
                        printf("In-order successor of %d does not exist.\n", target->info);
                    }
                } else {
                    printf("Node %d not found in the tree.\n", data);
                }
                break;

            case 3:
                printf("In-order traversal of the BST: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
