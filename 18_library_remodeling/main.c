#include "main.h"
#include "func.h"

int main()
{
    struct Book books[MAX_BOOK+1];
    int curr_book = 0, request;

    while (curr_book <= MAX_BOOK)
    {
        printf("What do you want to do?\n");
        printf("(1) ADD BOOK\n");
        printf("(2) SEARCH BOOK\n");
        printf("(3) RENT BOOK\n");
        printf("(4) RETURN BOOK\n");
        printf("(5) Exit\n");
        printf("Enter your request : ");
        scanf("%d", &request);
        printf("\n");

        if (request == 1) add_book(books, &curr_book);
        else if (request == 2) search_book(books, curr_book);
        else if (request == 3) rent_book(books, curr_book);
        else if (request == 4) return_book(books, curr_book);
        else if (request == 5) 
        {
            printf(">>> Program Exit <<<\n");
            break;
        }
        else printf("!! Request Error !!\n\n");
    }

    return 0;
}