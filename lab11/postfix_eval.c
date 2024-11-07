#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
}NODE;

NODE* createNode(char data) {
    NODE* newnode = malloc(sizeof(NODE));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

NODE* constructTree(char postfix[]) {
    NODE* stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            stack[++top] = createNode(postfix[i]);
        }
        else if (isOperator(postfix[i])) {
            NODE* newnode = createNode(postfix[i]);

            newnode->right = stack[top--];
            newnode->left = stack[top--];  
            stack[++top] = newnode;
        }
    }
    return stack[top];
}

int evalExpTree(NODE* root) {
    if (!isOperator(root->data)) {
        return root->data - '0';
    }

    int leftVal = evalExpTree(root->left);
    int rightVal = evalExpTree(root->right);

    switch (root->data) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
    }

    return 0;
}

void inorder(NODE* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}

void main() {
    char postfix[100];
    
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    
    NODE* root = constructTree(postfix);

    printf("In-order Traversal of Expression Tree: ");
    inorder(root);

    int result = evalExpTree(root);
    printf("\nResult of the expression: %d", result);

 }