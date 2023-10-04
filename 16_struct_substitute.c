#include <stdio.h>

struct TEST1
{
    int i;
    char c;
};
void test1(void);

struct TEST2
{
    int i;
    char str[30];
};
void test2(void);
void copy_str(char *str, char *copy);


int main()
{
    test2();
    return 0;
}

void test1(void)
{
    struct TEST1 st, st_copy;

    st.i = 1;
    st.c = 'c';

    st_copy = st;
    printf("st_copy.i = %d\n", st_copy.i);
    printf("st.copy.c = %c\n", st_copy.c);
}

void test2(void)
{
    struct TEST2 a, b;

    copy_str(a.str, "hello, world");
    a.i = 3;

    b = a;
    printf("b.str = %s\n", b.str);
    printf("b.i = %d\n", b.i);
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

