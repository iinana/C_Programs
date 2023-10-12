#include "main.h"
#include "library.h"

void program_exit(Book *books, int curr_book)
{
    int request;
    printf("(1) Save Book List\n");
    printf("(2) Exit Without Save\n");
    printf("Choose the Option : ");
    scanf("%d", &request);

    if (request == 2)
    {
        getchar();
        printf("Are you sure about not saving? : Yes(Press 1) / No(Press 0) ");
        scanf("%d", &request);

        if (request == 1) return;
    }
    
    char file[CHAR_LIMIT];
    printf("Enter the File Name to Save : ");
    scanf("%s", file);

    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        printf("Failed to Open File");
        return;
    }

    fprintf(fp, "Title / Author / Publisher / Owned / Rented / Availability\n");
    for (int i = 0; i < curr_book; i++)
    {
        Book b = books[i];
        fprintf(fp, "%s / %s / %s / %d / %d / ", b.title, b.author, b.publisher, b.owned, b.rented);
        if (b.avail) fprintf(fp, "O\n");
        else fprintf(fp, "X\n");
    }

    printf("%d books are saved in %s\n", curr_book, file);
    printf(">>> Program Exit <<<\n");
}