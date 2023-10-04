#include <stdio.h>

struct TEST
{
    int age;
    int gender;
    char name[20];
};
void set_human(struct TEST *a, int age, int gender, char *name);
void copy_str(char *str, char *copy);

int main()
{
    struct TEST human;
    set_human(&human, 10, 1, "Lee");

    printf("AGE : %d // Gender : %d // Name : %s\n", human.age, human.gender, human.name);
    return 0;
}

void set_human(struct TEST *a, int age, int gender, char *name)
{
    a->age = age;
    a->gender = gender;
    copy_str(a->name, name);
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
