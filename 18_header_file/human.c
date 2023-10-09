#include <stdio.h>
#include "human.h"


struct Human Create_Human(char *name, int age, int gender)
{
    struct Human h;
    h.age = age;
    h.gender = gender;

    int i = 0;
    while (name[i]) 
    {
        h.name[i] = name[i];
        i++;
    }
    h.name[i] = '\0';

    return h;
}

void Print_Human(struct Human *h)
{
    printf("Name : %s\n", h->name);
    printf("Age : %d\n", h->age);
    printf("Gender : %s\n", (h->gender == MALE) ? "Male" : "Female");
}