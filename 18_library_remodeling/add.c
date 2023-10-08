#include "main.h"
#include "func.h"

/* (1) Add function */
void add_book(struct Book *books, int *curr_book)
{
    printf("[Title] ");
    scanf("%s", books[*curr_book].title);
    printf("[Author] ");
    scanf("%s", books[*curr_book].author);
    printf("[Publisher] ");
    scanf("%s", books[*curr_book].publisher);
    printf("[Num of Books Bought] ");
    scanf("%d", &books[*curr_book].owned);

    books[*curr_book].rented = 0;
    books[*curr_book].avail = 1;

    ++*curr_book;
    printf("\n");
}
