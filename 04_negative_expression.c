#include <stdio.h>

void overflow(void);
void unsign(void);

int main()
{
    unsign();
    return 0;
}

void overflow(void)
{
    int a = 2147483647;
    printf("a = %d\n", a);

    printf("overflowed a = %d\n", ++a);
}

void unsign(void)
{
    unsigned int b = -1;
    printf("value that express -1 with 'unsigned int' = %u\n", b);
}