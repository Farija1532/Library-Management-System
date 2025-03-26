#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_USERS 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int isBorrowed;
    int borrowerId;
} Book;

typedef struct {
    int id;
    char name[50];
} User;

Book books[MAX_BOOKS];
User users[MAX_USERS];
int bookCount = 0;
int userCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &books[bookCount].id);
    printf("Enter book title: ");
    scanf(" %[^\n]", books[bookCount].title);
    printf("Enter book author: ");
    scanf(" %[^\n]", books[bookCount].author);
    books[bookCount].isBorrowed = 0;
    books[bookCount].borrowerId = -1;
    bookCount++;
    printf("Book added successfully.\n");
}

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    printf("Enter user ID: ");
    scanf("%d", &users[userCount].id);
    printf("Enter user name: ");
    scanf(" %[^\n]", users[userCount].name);
    userCount++;
    printf("User added successfully.\n");
}

void borrowBook() {
    int bookId, userId;
    printf("Enter book ID: ");
    scanf("%d", &bookId);
    printf("Enter user ID: ");
    scanf("%d", &userId);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && !books[i].isBorrowed) {
            books[i].isBorrowed = 1;
            books[i].borrowerId = userId;
            printf("Book borrowed successfully.\n");
            return;
        }
    }
    printf("Book not found or already borrowed.\n");
}

void returnBook() {
    int bookId;
    printf("Enter book ID: ");
    scanf("%d", &bookId);

    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == bookId && books[i].isBorrowed) {
            books[i].isBorrowed = 0;
            books[i].borrowerId = -1;
            printf("Book returned successfully.\n");
            return;
        }
    }
    printf("Book not found or not borrowed.\n");
}

void displayAvailableBooks() {
    printf("Available Books:\n");
    for (int i = 0; i < bookCount; i++) {
        if (!books[i].isBorrowed) {
            printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
        }
    }
}

void displayBorrowedBooks() {
    printf("Borrowed Books:\n");
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isBorrowed) {
            printf("ID: %d, Title: %s, Author: %s, Borrower ID: %d\n", books[i].id, books[i].title, books[i].author, books[i].borrowerId);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add a Book\n");
        printf("2. Add a User\n");
        printf("3. Borrow a Book\n");
        printf("4. Return a Book\n");
        printf("5. Display Available Books\n");
        printf("6. Display Borrowed Books\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addUser();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                displayAvailableBooks();
                break;
            case 6:
                displayBorrowedBooks();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
