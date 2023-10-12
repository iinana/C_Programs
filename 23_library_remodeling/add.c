#include "main.h"
#include "library.h"

/* (1) Add function */
void add_book(Book *books, int *curr_book, int MAX_BOOK)
{
    char file[CHAR_LIMIT];
    printf("Enter the file name with [Title] [Author] [Publisher] [Num of books] : ");
    scanf("%s", file);

    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("Faile to Open File\n");
        return;
    }

    char data[CHAR_LIMIT];
    int count = 0, len;
    while (*curr_book < MAX_BOOK)
    {
        fscanf(fp, "%s", data);
        strcpy(books[*curr_book].title, data);

        fscanf(fp, "%s", data);
        strcpy(books[*curr_book].author, data);

        fscanf(fp, "%s", data);
        strcpy(books[*curr_book].publisher, data);

        fscanf(fp, "%s", data);
        books[*curr_book].owned = atoi(data);

        books[*curr_book].rented = 0;
        books[*curr_book].avail = 1;

        print_searched(books, *curr_book);

        ++*curr_book;
        count++;
    }
    printf("Complete to Add %d Number of Books\n", count);
    fclose(fp);
}