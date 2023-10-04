#include <stdio.h>

void ex_pet(void);

int main()
{
    ex_pet();
    return 0;
}

void ex_pet(void)
{
    int input;

    printf("MY PET\n");
    printf("What do you want to do?\n");
    printf("1. Feeding\n");
    printf("2. Washing\n");
    printf("3. Sleeping\n");

    scanf("%d", &input);

    switch (input)
    {
    case 1:
        printf("Taste Good\n");
        break;
    case 2:
        printf("Feel Good\n");
        break;
    case 3:
        printf("zzz...\n");
        break;
    default:
        printf("I don't know what you want\n");
        break;
    }
}