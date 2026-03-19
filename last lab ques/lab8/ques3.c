
#include <stdio.h>


struct Book {
    int book_id;
    char title[100];
    char author[100];
    float price;
};


void printBook(struct Book b) {
    printf("\n--- Book Details ---\n");
    printf("Book ID   : %d\n", b.book_id);
    printf("Title     : %s\n", b.title);
    printf("Author    : %s\n", b.author);
    printf("Price     : %.2f\n", b.price);
}

int main() {
    struct Book myBook;

   
    printf("Enter Book ID: ");
    scanf("%d", &myBook.book_id);

    printf("Enter Title: ");
    scanf(" %[^\n]", myBook.title); 
    printf("Enter Author Name: ");
    scanf(" %[^\n]", myBook.author);

    printf("Enter Price: ");
    scanf("%f", &myBook.price);

    printBook(myBook);

    return 0;
}