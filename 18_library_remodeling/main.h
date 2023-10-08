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