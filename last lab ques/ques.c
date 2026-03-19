#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char title[50];
    char author[30];
    float price;
} Book;

void inputBooks(Book *b, int n);
void displayBooks(Book *b, int n);
void sortBooksByTitle(Book *b, int n);

int main() {
    int n, choice;
      while (1) {
        printf("Enter number of books: ");
        if (scanf("%d", &n) == 1) {
            break; 
        } else {
            printf("Invalid input! Try again.\n");
            while (getchar() != '\n');
        }
    }
    printf("You entered: %d\n", n);
   
    Book *b = (Book *)malloc(n * sizeof(Book));
    if (b == NULL) {
        printf("error!file not found\n");
        return 1;
    }

    inputBooks(b, n);

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Display Books\n");
        printf("2. Sort Books Alphabetically by Title (A → Z)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBooks(b, n);
                break;

            case 2:
                sortBooksByTitle(b, n);
                printf("\nBooks sorted alphabetically by title!\n");
                break;

            case 3:
                free(b);
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void inputBooks(Book *b, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Book %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &b[i].id);

        printf("Title: ");
        scanf(" %[^\n]", b[i].title);

        printf("Author: ");
        scanf(" %[^\n]", b[i].author);

        printf("Price: ");
        scanf("%f", &b[i].price);
    }
}

void displayBooks(Book *b, int n) {
    printf("\n----- BOOK DETAILS -----\n");

    for (int i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("ID      : %d\n", b[i].id);
        printf("Title   : %s\n", b[i].title);
        printf("Author  : %s\n", b[i].author);
        printf("Price   : %.2f\n", b[i].price);
    }
}

void sortBooksByTitle(Book *b, int n) {
    Book temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (strcmp(b[j].title, b[j + 1].title) > 0) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
}