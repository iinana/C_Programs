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