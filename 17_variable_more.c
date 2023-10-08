#include <stdio.h>

/* local variable */
void local_var(void);

/* global variable */
void global_var(void);
int global = 3;  

void count_func_call(void);
int how_many_called = 0; // automatically initialize by 0

/* static variable - not destroyed even if it if out of their own local */
void static_var(void);
int* destroyed_pointer(void);  // problem of local variable
int* non_destroyed(void);
void count_with_static(void);


int main()
{
    static_var();
    return 0;
}

void local_var(void)
{
    int a = 4;
    {
        int a = 2;
        printf("local a = %d\n", a);
    } // curly braket is one 'local'
    printf("a outside the local = %d\n", a);
}

void global_var(void)
{
    global++;
    printf("global = %d\n", global);

    count_func_call();
    count_func_call();
    count_func_call();
}

void count_func_call(void)
{
    how_many_called++;
    printf("called : %d\n", how_many_called);
}

void static_var(void)
{
    /* LOCAL VAR ERROR : a is already destroyed when destroyed_pointer() func was over */
    // int *pa = destroyed_pointer();
    // printf("%d\n", *pa);

    /* STATIC VAR */
    int *pa = non_destroyed();
    printf("%d\n", *pa);

    /* usage of static var */
    count_with_static();
    count_with_static();
    count_with_static();
    count_with_static();

}

// int* destroyed_pointer(void)
// {
//     int a = 2;
//     return &a;
// }

int* non_destroyed(void)
{
    static int a = 2;
    return &a;
}

void count_with_static(void)
{
    static int how_many_called2 = 0;
    // even if func called many times, it initializes just one time

    how_many_called2++;
    printf("function called : %d\n", how_many_called2);
}