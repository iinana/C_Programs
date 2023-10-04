#include <stdio.h>

struct test
{
    int a, b;
};
void pointer_basic(void);
void new_sign(void);

struct TEST
{
    int c;
    int *pointer;
};
void pointer_in_struct(void);

void pointer_prac(void);
void add_one(int *a);


int main()
{
    pointer_prac();
    return 0;
}

void pointer_basic(void)
{
    struct test st;
    struct test *ptr;

    ptr = &st;

    (*ptr).a = 1;
    (*ptr).b = 2;

    printf("a memeber of st : %d\n", st.a);
    printf("b memeber of st : %d\n", st.b);
}

void new_sign(void)
{
    struct test st;
    struct test *ptr;

    ptr = &st;

    ptr->a = 1;
    ptr->b = 2;

    printf("a memeber of st : %d\n", st.a);
    printf("b memeber of st : %d\n", st.b);
}

void pointer_in_struct(void)
{
    struct TEST t;
    struct TEST *pt = &t;
    int i = 0;

    t.pointer = &i;

    /* '.' is prior to '*' */
    *t.pointer = 3;   // == [*(t.pointer) = 3]
    printf("i = %d\n", i);

    /* '->' is prior to '*' */
    *pt->pointer = 4;  // == [*(pt->pointer) = 4]
    printf("i = %d\n", i);
}

void pointer_prac(void)
{
    struct TEST t;
    struct TEST *pt = &t;

    /* '.' is prior to '& */
    pt->c = 0;
    add_one(&t.c);
    printf("t.c = %d\n", t.c);

    /* '->' is prior to '& */
    add_one(&pt->c);   // [&pt->c] == [&(pt->c)]
    printf("t.c : %d\n", t.c);
}

void add_one(int *a)
{
    *a += 1;
}