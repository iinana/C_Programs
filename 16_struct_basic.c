#include <stdio.h>

struct Human 
{
    int age;
    int height;
    int weight;
};
void struct_human(void);

struct Book
{
    char title[50];
    char author[50];
    char publisher[50];
    int borrowed;
};
void struct_book(void);
void copy_str(char *str, char *copy);

int main()
{
    struct_book();
    return 0;
}

void struct_human(void)
{
    struct Human Psi;

    Psi.age = 99;
    Psi.height = 185;
    Psi.weight = 80;

    printf("Info about Psi\n");
    printf("Age    : %3d\n", Psi.age);
    printf("Height : %3d\n", Psi.height);
    printf("Weight : %3d\n", Psi.weight);
}

void struct_book(void)
{
    struct Book harry;

    copy_str(harry.title, "Harry Potter");
    copy_str(harry.author, "J.K. Rolling");
    copy_str(harry.publisher, "Scholastic");
    harry.borrowed = 0;

    printf("Book Title  : %s\n", harry.title);
    printf("Author Name : %s\n", harry.author);
    printf("Publisher   : %s\n", harry.publisher);
}

void copy_str(char *str, char *copy)
{
    while (*copy)
    {
        *str = *copy;
        str++;
        copy++;
    }
    *str = '\0';
}