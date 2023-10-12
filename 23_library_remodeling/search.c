#include "main.h"
#include "library.h"

/* Search Function */
void search_book(Book *books, int curr_book)
{
    int request;
    printf("I want to search book \n");
    printf("(1) With Title\n");
    printf("(2) With Autor\n");
    printf("(3) With Publisher\n");
    printf("(4) Exit Searching\n");
    printf("Enter your request : ");
    scanf("%d", &request);
    printf("\n");

    int search_res[curr_book];
    int count = 0;
    switch (request)
    {
    case 1:
        title_search(books, curr_book, search_res, &count);
        break;
    case 2:
        author_search(books, curr_book, search_res, &count);
        break;
    case 3:
        publisher_search(books, curr_book, search_res, &count);
        break;
    default:
        printf("!! Requset Error !!\n\n");
        getchar();
        return;
    }

    if (count == 0) printf("No Result\n");
    else
    {
        printf("Search Result (%d books founds)\n", count);
        printf("-------------------------------------------------------------------\n");
        for (int i = 0; i < count; i++) print_searched(books, search_res[i]);
    }
    printf("\n");
}

void title_search(Book *books, int curr_book, int *idx, int *count)
{
    char q[CHAR_LIMIT];
    printf("Enter title of book you want to find : ");
    scanf("%s", q);

    for (int i = 0; i < curr_book; i++)
    {
        if (strcasestr(books[i].title, q))
        {
            idx[*count] = i;
            ++*count;
        }
    }
}

void author_search(Book *books, int curr_book, int *idx, int *count)
{
    char q[CHAR_LIMIT];
    printf("Enter author of book you want to find : ");
    scanf("%s", q);

    for (int i = 0; i < curr_book; i++)
    {
        if (strcasestr(books[i].author, q))
        {
            idx[*count] = i;
            ++*count;
        }
    }
}

void publisher_search(Book *books, int curr_book, int *idx, int *count)
{
    char q[CHAR_LIMIT];
    printf("Enter publisher of book you want to find : ");
    scanf("%s", q);

    for (int i = 0; i < curr_book; i++)
    {
        if (strcasestr(books[i].publisher, q))
        {
            idx[*count] = i;
            ++*count;
        }
    }
}

int strcasestr(char *str, char *q)
{
    while (*str && *q)
    {
        if (tolower(*str) != tolower(*q)) return 0;
        str++;
        q++;
    }
    if (*q) return 0;
    else return 1;
}

void print_searched(Book *books, int book_idx)
{
    printf("[Book Code] %d\n", book_idx);
    printf("[Title] %s\n", books[book_idx].title);
    printf("[Author] %s\n", books[book_idx].author);
    printf("[Publisher] %s\n", books[book_idx].publisher);
    printf("[Rent Status] %d/%d\n", books[book_idx].rented, books[book_idx].owned);
    printf("[Availability] %c\n", (books[book_idx].avail == 1) ? 'O' : 'X');
    printf("-------------------------------------------------------------------\n");
}