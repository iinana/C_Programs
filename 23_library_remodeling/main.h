#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define CHAR_LIMIT 50

typedef struct BOOK
{
    char title[CHAR_LIMIT];
    char author[CHAR_LIMIT];
    char publisher[CHAR_LIMIT];
    int owned;
    int rented;
    int avail;
} Book;