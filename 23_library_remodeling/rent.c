#include "main.h"
#include "library.h"

/* (3) Rent Function */
void rent_book(Book *books, int curr_book)
{
    int book_idx, check;
    printf("Enter code of book : ");
    scanf("%d", &book_idx);

    if (book_idx >= curr_book) 
    {
        printf("[Code Error] Entered code is not available\n");
        return;
    }
    else if (books[book_idx].avail == 1)
    {
        printf("Rent '%s (written by %s)'\n", books[book_idx].title, books[book_idx].author);
        printf("Yes(Press 1) / No(Press 0) : ");
        scanf("%d", &check);

        if (check)
        {
            printf("Rent Success!\n");
            ++books[book_idx].rented;
            if (books[book_idx].rented == books[book_idx].owned) books[book_idx].avail = 0;
        }
    }
    else printf("Every book is alreday rented\n");
    printf("\n");
}