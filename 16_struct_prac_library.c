#include <stdio.h>
#define CHAR_LIMIT 50
#define MAX_BOOK 100

struct Book
{
    char title[CHAR_LIMIT];
    char author[CHAR_LIMIT];
    char publisher[CHAR_LIMIT];
    int owned;
    int rented;
    int avail;
};

/* (1) Add function */
void add_book(struct Book *books, int *curr_book);

/* (2) Search Function */
void search_book(struct Book *books, int curr_book);
void title_search(struct Book *books, int curr_book, int *idx, int *count);
void author_search(struct Book *books, int curr_book, int *idx, int *count);
void publisher_search(struct Book *books, int curr_book, int *idx, int *count);
int compare(char *str1, char *str2);
void print_searched(struct Book *books, int book_idx);

/* (3) Rent Fuction */
void rent_book(struct Book *books, int curr_book);

/* (4) Return Function */
void return_book(struct Book *books, int curr_book);


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

/* (3) Rent Function */
void rent_book(struct Book *books, int curr_book)
{
    int book_idx, check;
    printf("Enter code of book : ");
    scanf("%d", &book_idx);

    if (book_idx >= curr_book) printf("[Code Error] Entered code is not available\n");
    else if (books[book_idx].avail == 1)
    {
        printf("Rent '%s (written by %s)'\n", books[book_idx].title, books[book_idx].author);
        printf("Yes(Press 1) / No(Press 0) : ");
        scanf("%d", &check);

        if (check == 1)
        {
            printf("Rent Success!\n");
            ++books[book_idx].rented;
            if (books[book_idx].rented == books[book_idx].owned) books[book_idx].avail = 0;
        }
    }
    else printf("Every book is alreday rented\n");
    printf("\n");
}

/* (4) Return Function */
void return_book(struct Book *books, int curr_book)
{
    int book_idx, check;
    printf("Enter code of book : ");
    scanf("%d", &book_idx);

    if (book_idx >= curr_book) printf("[Code Error] Entered code is not available\n");
    else if (books[book_idx].rented == 0) printf("[Return Error] No return history for this book\n");
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