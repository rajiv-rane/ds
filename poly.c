#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure for representing a polynomial term
struct poly {
    int cf;     // Coefficient
    int px, py, pz;  // Powers of x, y, and z
    int flag;   // Flag to mark terms during addition
    struct poly *next;  // Pointer to the next term
};

typedef struct poly node; // Typedef for simplicity

node *temp, *p; // Global variables for temporary nodes
int x, y, z, co, ch; // Global variables for input coefficients and powers

// Function to create a new polynomial term
node *getpoly() {
    temp = (node *)malloc(sizeof(node));
    return temp;
}

// Function to display a polynomial
void display(node *head) {
    p = head->next;
    printf("\n");
    while (p != head) {
        printf("\t+ %d x^%d y^%d z^%d", p->cf, p->px, p->py, p->pz);
        p = p->next;
    }
}

// Function to insert a term at the rear of the polynomial
node *insert_rear(int co, int x, int y, int z, node *head) {
    temp = getpoly();
    temp->cf = co;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    p = head->next;
    while (p->next != head) {
        p = p->next;
    }
    p->next = temp;
    temp->next = head;
    return head;
}

// Function to read a polynomial from user input
node *read_poly(node *head) {
    do {
        printf("\nEnter coeff: ");
        scanf("%d", &co);
        printf("\nEnter x, y, z powers (0 indicates no term): ");
        scanf("%d%d%d", &x, &y, &z);
        head = insert_rear(co, x, y, z, head);
        printf("\nIf you wish to continue press 1 otherwise 0: ");
        scanf("%d", &ch);
    } while (ch != 0);
    return head;
}

// Function to add two polynomials and store the result in a third polynomial
node *add_poly(node *h1, node *h2, node *h3) {
    node *p1, *p2;
    int x1, x2, y1, y2, z1, z2, cf1, cf2, cf;
    p1 = h1->next;
    while (p1 != h1) {
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        cf1 = p1->cf;
        p2 = h2->next;
        while (p2 != h2) {
            x2 = p2->px;
            y2 = p2->py;
            z2 = p2->pz;
            cf2 = p2->cf;
            if (x1 == x2 && y1 == y2 && z1 == z2)
                break;
            p2 = p2->next;
        }
        if (p2 != h2) {
            cf = cf1 + cf2;
            p2->flag = 1;
            if (cf != 0)
                h3 = insert_rear(cf, x1, y1, z1, h3);
        } else
            h3 = insert_rear(cf1, x1, y1, z1, h3);
        p1 = p1->next;
    }
    p2 = h2->next;
    while (p2 != h2) {
        if (p2->flag == 0)
            h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->next;
    }
    return h3;
}

// Function to evaluate a polynomial
void evaluate(node *h1) {
    node *head;
    int result = 0;
    head = h1;
    printf("\nEnter x, y, z, terms to evaluate:\n");
    scanf("%d%d%d", &x, &y, &z);
    do {
        h1 = h1->next;
        result = result + (h1->cf * pow(x, h1->px) * pow(y, h1->py) * pow(z, h1->pz));
    } while (h1->next != head);
    printf("\nPolynomial result is: %d", result);
}

int main() {
    node *h1, *h2, *h3, *he;
    int ch;

    // Initialize polynomial heads
    he = getpoly();
    h1 = getpoly();
    h2 = getpoly();
    h3 = getpoly();
    he->next = he;
    h1->next = h1;
    h2->next = h2;
    h3->next = h3;

    // Main menu loop
    while (1) {
        printf("\n\n1. Evaluate polynomial\n2. Add two polynomials\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter polynomial to evaluate:\n");
                he = read_poly(he);
                display(he);
                evaluate(he);
                break;
            case 2:
                printf("\nEnter the first polynomial:");
                h1 = read_poly(h1);
                printf("\nEnter the second polynomial:");
                h2 = read_poly(h2);
                h3 = add_poly(h1, h2, h3);
                printf("\nFirst polynomial is: ");
                display(h1);
                printf("\nSecond polynomial is: ");
                display(h2);
                printf("\nThe sum of 2 polynomials is: ");
                display(h3);
                break;
            case 3:
                exit(0);
                break;
        }
    }
    return 0;
}
