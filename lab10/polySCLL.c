#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff;  
    int exp;    
    struct Node* next;
}NODE;

NODE* createHeaderNode() {
    NODE* header = (NODE*)malloc(sizeof(NODE));
    header->coeff = 0;//no. of terms
    header->exp = 0;//highest degree
    header->next = header;  
    return header;
}

NODE* createNode(int coeff, int exp) {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode;  
    return newNode;
}

NODE* insertNode(NODE* header, int coeff, int exp) {
    NODE* newNode = createNode(coeff, exp);
    NODE* temp = header;

    if (header->next == header) {
        header->next = newNode;
        newNode->next = header;
        header->coeff += 1;  
        header->exp = exp;   
        return header;
    }

    while (temp->next != header && temp->next->exp > exp) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    header->coeff += 1;  
    if (exp > header->exp) {
        header->exp = exp;   
    }
    return header;
}

void displayPolynomial(NODE* header) {
    NODE* temp = header->next; 

    if (header->next == header) {
        printf("Polynomial is empty!\n");
        return;
    }

    printf("Polynomial: ");
    do {
        printf("%d x^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != header) {
            printf(" + ");
        }
    } while (temp != header);
    printf("\n");
    printf("Number of terms: %d\n", header->coeff);
    printf("Highest degree: %d\n", header->exp);
}

NODE* subtractPolynomials(NODE* poly1, NODE* poly2) {
    NODE* result = createHeaderNode();
    NODE* p1 = poly1->next;
    NODE* p2 = poly2->next;

    while (p1 != poly1 && p2 != poly2) {
        if (p1->exp == p2->exp) {
            int newCoeff = p1->coeff - p2->coeff;
            if (newCoeff != 0) {
                insertNode(result, newCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->exp > p2->exp) {
            insertNode(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else {
            insertNode(result, -p2->coeff, p2->exp); 
            p2 = p2->next;
        }
    }

    while (p1 != poly1) {
        insertNode(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != poly2) {
        insertNode(result, -p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

NODE* multiplyPolynomials(NODE* poly1, NODE* poly2) {
    NODE* result = createHeaderNode();
    NODE* p1 = poly1->next;
    NODE* p2;

    while (p1 != poly1) {
        p2 = poly2->next;
        while (p2 != poly2) {
            int newCoeff = p1->coeff * p2->coeff;
            int newExp = p1->exp + p2->exp;
            insertNode(result, newCoeff, newExp);
            p2 = p2->next;
        }
        p1 = p1->next;
    }

    return result;
}

NODE* createPolynomial() {
    NODE* header = createHeaderNode();
    int n, coeff, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertNode(header, coeff, exp);
    }
    return header;
}

int main() {
    NODE *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Input polynomial 1\n");
        printf("2. Input polynomial 2\n");
        printf("3. Subtract polynomials\n");
        printf("4. Multiply polynomials\n");
        printf("5. Display polynomial 1\n");
        printf("6. Display polynomial 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Input Polynomial 1:\n");
                poly1 = createPolynomial();
                break;
            case 2:
                printf("Input Polynomial 2:\n");
                poly2 = createPolynomial();
                break;
            case 3:
                printf("Subtracting Polynomials:\n");
                result = subtractPolynomials(poly1, poly2);
                printf("Result: ");
                displayPolynomial(result);
                break;
            case 4:
                printf("Multiplying Polynomials:\n");
                result = multiplyPolynomials(poly1, poly2);
                printf("Result: ");
                displayPolynomial(result);
                break;
            case 5:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                break;
            case 6:
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
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