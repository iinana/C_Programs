#include "main.h"
#include "func.h"

/* Search Function */
void search_book(struct Book *books, int curr_book)
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

    int search_res[MAX_BOOK];
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

void title_search(struct Book *books, int curr_book, int *idx, int *count)
{
    char q[CHAR_LIMIT];
    printf("Enter title of book you want to find : ");
    scanf("%s", q);

    for (int i = 0; i < curr_book; i++)
    {
        if (compare(books[i].title, q))
        {
            idx[*count] = i;
            ++*count;
        }
    }
}

void author_search(struct Book *books, int curr_book, int *idx, int *count)
{
    char q[CHAR_LIMIT];
    printf("Enter author of book you want to find : ");
    scanf("%s", q);

    for (int i = 0; i < curr_book; i++)
    {
        if (compare(books[i].author, q))
        {
            idx[*count] = i;
            ++*count;
        }
    }
}

void publisher_search(struct Book *books, int curr_book, int *idx, int *count)
{
    char q[CHAR_LIMIT];
    printf("Enter publisher of book you want to find : ");
    scanf("%s", q);

    for (int i = 0; i < curr_book; i++)
    {
        if (compare(books[i].publisher, q))
        {
            idx[*count] = i;
            ++*count;
        }
    }
}

int compare(char *str1, char *str2)
{
    int i;
    while (*str1 && *str2)
    {
        if (*str1 == *str2)
        {
            i = 0;
            while (str1[i] && str2[i])
            {
                if (str1[i] != str2[i]) break;
                else i++;
            }
            if (!str2[i]) return 1;
        }
        ++str1;
    }
    return 0;
}

void print_searched(struct Book *books, int book_idx)
{
    printf("[Book Code] %d\n", book_idx);
    printf("[Title] %s\n", books[book_idx].title);
    printf("[Author] %s\n", books[book_idx].author);
    printf("[Publisher] %s\n", books[book_idx].publisher);
    printf("[Rent Status] %d/%d\n", books[book_idx].rented, books[book_idx].owned);
    printf("[Availability] %c\n", (books[book_idx].avail == 1) ? 'O' : 'X');
    printf("-------------------------------------------------------------------\n");
}