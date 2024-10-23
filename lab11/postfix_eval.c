#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the structure of a node in the expression tree
struct Node {
    char data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to build the expression tree from postfix expression
struct Node* constructTree(char postfix[]) {
    struct Node* stack[100];
    int top = -1;

    // Traverse through every character of the postfix expression
    for (int i = 0; postfix[i] != '\0'; i++) {
        // If the character is an operand, push it onto the stack
        if (isalnum(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        }
        // If the character is an operator
        else if (isOperator(postfix[i])) {
            struct Node* newNode = createNode(postfix[i]);

            // Pop two operands from the stack and attach them to the new operator node
            newNode->right = stack[top--];  // Right child
            newNode->left = stack[top--];   // Left child

            // Push the new node back onto the stack
            stack[++top] = newNode;
        }
    }

    // The final node in the stack will be the root of the expression tree
    return stack[top];
}

// Function to evaluate the expression tree
int evaluateExpressionTree(struct Node* root) {
    // If the node is a leaf node (operand), return its integer value
    if (!isOperator(root->data)) {
        return root->data - '0';  // Convert char to int
    }

    // Recursively evaluate the left and right subtrees
    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);

    // Apply the operator at the root
    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }

    return 0;
}

// In-order Traversal (for testing purposes)
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

// Main function to test the program
int main() {
    char postfix[100];
    
    printf("Enter a valid postfix expression (e.g. '53+82-*'): ");
    scanf("%s", postfix);
    
    // Construct the expression tree
    struct Node* root = constructTree(postfix);

    // Display in-order traversal of the constructed expression tree
    printf("In-order Traversal of Expression Tree: ");
    inorderTraversal(root);
    printf("\n");

    // Evaluate the expression tree
    int result = evaluateExpressionTree(root);
    printf("Result of the expression: %d\n", result);

    return 0;
}
