#include <stdio.h>

/* define for array of books' info */
#define BOOK_NUM 100
#define COLUMN 6
#define CHAR_LIMIT 50

/* define column number of info */
#define TITLE 0
#define AUTHOR 1
#define PUBLISH 2
#define OWNED 3
#define RENTED 4
#define AVAIL 5

/* (1) add func */
void add_book(char (*books)[COLUMN][CHAR_LIMIT], int *curr_book);

/* (2) search func */
void search_book(char (*books)[COLUMN][CHAR_LIMIT], int curr_book);
void searching(int request, char (*books)[COLUMN][CHAR_LIMIT], int curr_book, int *index, int *count);
int check_include(char *str1, char *str2);
int print_searched(char (*books)[COLUMN][CHAR_LIMIT], int book_idx);

/* (3) rent func */
void rent_book(char (*books)[COLUMN][CHAR_LIMIT], int curr_book);

/* (4) Return func */
void return_book(char (*books)[COLUMN][CHAR_LIMIT], int curr_book);


int main()
{
    char books[BOOK_NUM][COLUMN][CHAR_LIMIT]; 
    // [num of books] [title/author/publisher/how many/rented/availability] [number of characters]
    int request;
    int curr_book = 0;

    while (1)
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

/* (1) add func */
void add_book(char (*books)[COLUMN][CHAR_LIMIT], int *curr_book)
{
    printf("[Title] ");
    scanf("%s", books[*curr_book][TITLE]);
    printf("[Author] ");
    scanf("%s", books[*curr_book][AUTHOR]);
    printf("[Publisher] ");
    scanf("%s", books[*curr_book][PUBLISH]);
    printf("[Num of Books Bought] ");
    scanf("%d", &books[*curr_book][OWNED][0]);

    books[*curr_book][RENTED][0] = 0;
    books[*curr_book][AVAIL][0] = 1;

    ++*curr_book;
    printf("\n");
}


/* (2) search func */
void search_book(char (*books)[COLUMN][CHAR_LIMIT], int curr_book)
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

    int index[BOOK_NUM];
    int count = 0;
    if (request == 1) searching(TITLE, books, curr_book, index, &count);
    else if (request == 2) searching(AUTHOR, books, curr_book, index, &count);
    else if (request == 3) searching(PUBLISH, books, curr_book, index, &count);
    else if (request == 4) return;
    else printf("!! Request Error !!\n");

    printf("Search Result (%d of books found)\n", count);
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) print_searched(books, index[i]);
    printf("\n");
}

void searching(int request, char (*books)[COLUMN][CHAR_LIMIT], int curr_book, int *index, int *count)
{
    char q[CHAR_LIMIT];
    printf("Enter the search keyword : ");
    scanf("%s", q);

    for (int i = 0; i < curr_book; i++)
    {
        if (check_include(books[i][request], q))
        {
            index[*count] = i;
            ++*count;
        }
    }
}

int check_include(char *str1, char *str2)
{
    int i;
    while (*str1)
    {
        if(*str1 == *str2)
        {
            i = 0;
            while(str2[i] && *str1)
            {
                str1++;
                i++;
                if(*str1 != str2[i]) break;
            }
            if (str2[i] == '\0') return 1;
        }
        str1++;
    }
    return 0;
}

int print_searched(char (*books)[COLUMN][CHAR_LIMIT], int book_idx)
{
    printf("[Book Code] %d\n", book_idx);
    printf("[Title] %s\n", books[book_idx][TITLE]);
    printf("[Author] %s\n", books[book_idx][AUTHOR]);
    printf("[Publisher] %s\n", books[book_idx][PUBLISH]);
    printf("[Rent Status] %d/%d\n", books[book_idx][RENTED][0], books[book_idx][OWNED][0]);
    printf("[Availability] %c\n", (books[book_idx][AVAIL][0] == 1) ? 'O' : 'X');
    printf("-------------------------------------------------------------------\n");
}


/* (3) rent func */
void rent_book(char (*books)[COLUMN][CHAR_LIMIT], int curr_book)
{
    int book_idx, check;
    printf("Enter code of book : ");
    scanf("%d", &book_idx);

    if (book_idx >= curr_book) printf("[Code Error] Entered code is not available\n");
    else if (books[book_idx][AVAIL][0] == 1)
    {
        printf("Rent '%s (written by %s)'\n", books[book_idx][TITLE], books[book_idx][AUTHOR]);
        printf("Yes(Press 1) / No(Press 0) : ");
        scanf("%d", &check);

        if (check == 1)
        {
            printf("Rent Success!\n");
            ++books[book_idx][RENTED][0];
            if (books[book_idx][RENTED][0] == books[book_idx][OWNED][0]) books[book_idx][AVAIL][0] = 0;
        }
    }
    else printf("Every book is alreday rented\n");
    printf("\n");
}

/* (4) Return func */
void return_book(char (*books)[COLUMN][CHAR_LIMIT], int curr_book)
{
    int book_idx, check;
    printf("Enter code of book : ");
    scanf("%d", &book_idx);

    if (book_idx >= curr_book) printf("[Code Error] Entered code is not available\n");
    else if (books[book_idx][RENTED][0] == 0) printf("[Return Error] There is no rented history for this book\n");
    else
    {
        printf("Return '%s (written by %s)'\n", books[book_idx][TITLE], books[book_idx][AUTHOR]);
        printf("Yes(Press 1) / No(Press 0) : ");
        scanf("%d", &check);

        if (check == 1) 
        {
            printf("Return Success!\n");
            books[book_idx][AVAIL][0] = 1;
            --books[book_idx][RENTED][0];
        }
    }
    printf("\n");
}
