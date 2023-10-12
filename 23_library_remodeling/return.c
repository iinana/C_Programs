#include "main.h"
#include "library.h"

/* (4) Return Function */
void return_book(Book *books, int curr_book)
{
    int book_idx, check;
    printf("Enter code of book : ");
    scanf("%d", &book_idx);

    if (book_idx >= curr_book) printf("[Code Error] Entered code is not available\n");
    else if (books[book_idx].rented == 0) printf("[Return Error] No rent history for this book\n");
    else
    {
        printf("Return '%s (written by %s)'\n", books[book_idx].title, books[book_idx].author);
        printf("Yes(Press 1) / No(Press 0) : ");
        scanf("%d", &check);

        if (check == 1)
        {
            printf("Return Success!\n");
            if (books[book_idx].rented == books[book_idx].owned) books[book_idx].avail = 1;
            --books[book_idx].rented;
        }
    }
    printf("\n");
}