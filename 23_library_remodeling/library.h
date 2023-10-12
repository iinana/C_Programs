#pragma once
#include "main.h"

/* (1) Add function */
void add_book(Book *books, int *curr_book, int MAX_BOOK);

/* (2) Search Function */
void search_book(Book *books, int curr_book);
void title_search(Book *books, int curr_book, int *idx, int *count);
void author_search(Book *books, int curr_book, int *idx, int *count);
void publisher_search(Book *books, int curr_book, int *idx, int *count);
int strcasestr(char *str, char *q);
void print_searched(Book *books, int book_idx);

/* (3) Rent Fuction */
void rent_book(Book *books, int curr_book);

/* (4) Return Function */
void return_book(Book *books, int curr_book);

/* (5) Exit Program */
void program_exit(Book *books, int curr_book);