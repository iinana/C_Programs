#include <stdio.h>

void change_val(int *pi);
void swap(int *pa, int *pb);

void increase_1(int *pary);
int maximum(int *pary);

void print_order(int *pary);

int main()
{
    /* function with pointer (why should we study pointer?) */
    int i = 0;
    printf("address of i var : %p\n", &i);
    printf("value of i before func call : %d\n", i);
    change_val(&i);
    printf("value of i after func call : %d\n", i);
    printf("\n");

    int a = 3, b = 5;
    printf("Before Swap : a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After Swap : a = %d, b = %d\n", a, b);
    printf("\n");


    /* array argument for function */
    int ary1[3];
    printf("enter three integers : ");
    for (int i = 0; i < 3; i++) scanf("%d", &ary1[i]);
    increase_1(ary1);
    printf("after adding one to array : ");
    for (int i = 0; i < 3; i++) printf("%d ", ary1[i]);
    printf("\n\n");

    int ary2[10];
    printf("enter ten integers : ");
    for (int i = 0; i < 10; i++) scanf("%d", &ary2[i]);
    printf("Maximum value amomg entered integers : %d\n", maximum(ary2));
    printf("\n");


    /* practice */
    print_order(ary2);

    return 0;
}

void change_val(int *pi)
{
    printf("------- in change_val function --------\n");    
    printf("value of pi : %p\n", pi);
    printf("value of var pointed by pi : %d\n", *pi);

    *pi = 3;
    printf("------- change_val function finished --------\n");    
}

void swap(int *pa, int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void increase_1(int *pary)
{
    for (int i = 0; i < 3; i++) pary[i]++;
}

int maximum(int *pary)
{
    int M = pary[0];
    for (int i = 1; i < 10; i++)
    {
        if (pary[i] > M) M = pary[i];
    }
    return M;
}

void print_order(int *pary)
{
    int M = maximum(pary);
    if (M == -1) return;

    printf("%d ", M);
    for (int i = 0; i < 10; i++)
    {
        if (pary[i] == M) pary[i] = -1;
    }
    print_order(pary);
}
