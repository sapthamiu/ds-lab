#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term (header node contains metadata)
struct Node {
    int coeff;  // Coefficient
    int exp;    // Exponent
    struct Node* next;
};

// Function to create a new header node (initializes with 0 terms or 0 degree)
struct Node* createHeaderNode() {
    struct Node* header = (struct Node*)malloc(sizeof(struct Node));
    header->coeff = 0;    // We can use this to store the number of terms
    header->exp = 0;      // This can store the highest degree if desired
    header->next = header;  // Circular list, so points to itself
    return header;
}

// Function to create a new node for a polynomial term
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = newNode;  // Circular list, so points to itself
    return newNode;
}

// Function to insert a node into the circular linked list in sorted order
void insertNode(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    struct Node* temp = head;

    // If the list is empty (just the header node), insert the first term
    if (head->next == head) {
        head->next = newNode;
        newNode->next = head;
        head->coeff += 1;  // Increase term count in the header
        head->exp = exp;   // Update highest degree in the header
        return;
    }

    // Insert at the appropriate position based on exponent (higher exponent first)
    while (temp->next != head && temp->next->exp > exp) {
        temp = temp->next;
    }

    // Insert the node
    newNode->next = temp->next;
    temp->next = newNode;

    // Update header information (number of terms and highest degree)
    head->coeff += 1;  // Increase term count in the header
    if (exp > head->exp) {
        head->exp = exp;   // Update highest degree if the new term has a larger exponent
    }
}

// Function to display the polynomial
void displayPolynomial(struct Node* head) {
    struct Node* temp = head->next; // Start from the first actual term

    if (head->next == head) {
        printf("Polynomial is empty!\n");
        return;
    }

    printf("Polynomial: ");
    do {
        printf("%d x^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != head) {
            printf(" + ");
        }
    } while (temp != head);
    printf("\n");
    printf("Number of terms: %d\n", head->coeff);
    printf("Highest degree: %d\n", head->exp);
}

// Function to subtract two polynomials
struct Node* subtractPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = createHeaderNode();
    struct Node* p1 = poly1->next;
    struct Node* p2 = poly2->next;

    // Traverse both polynomials
    while (p1 != poly1 && p2 != poly2) {
        // If exponents match, subtract coefficients
        if (p1->exp == p2->exp) {
            int newCoeff = p1->coeff - p2->coeff;
            if (newCoeff != 0) {
                insertNode(result, newCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // If poly1 has a higher exponent
        else if (p1->exp > p2->exp) {
            insertNode(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        // If poly2 has a higher exponent
        else {
            insertNode(result, -p2->coeff, p2->exp); // Subtract by inserting negative of poly2
            p2 = p2->next;
        }
    }

    // Add remaining terms of poly1
    while (p1 != poly1) {
        insertNode(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Add remaining terms of poly2
    while (p2 != poly2) {
        insertNode(result, -p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = createHeaderNode();
    struct Node* p1 = poly1->next;
    struct Node* p2;

    // Multiply each term of poly1 with every term of poly2
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

// Function to create a polynomial by taking input from the user
struct Node* createPolynomial() {
    struct Node* head = createHeaderNode(); // Initialize header node
    int n, coeff, exp;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        insertNode(head, coeff, exp);
    }
    return head;
}

// Main function with menu-driven approach
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
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
