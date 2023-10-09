#include <stdio.h>

void add_one(int *p)
{
    (*p) += 1;
}

int read_char(void *p, int byte);

int main()
{
    /* function returning void type */
    int a = 1;
    printf("Before : %d\n", a);
    add_one(&a);
    printf("After : %d\n", a);

    /* void type pointer */
    // void a;  // cannot make void type variable
    void *pb;
    double b = 123.3;
    pb = &b;  // void type pointer can get any type
    printf("%lf\n", *(double *)pb);

    /* usage of void type pointer */
    int arr[1] = {0x12345678};
    printf("%x\n", arr[0]);
    read_char(arr, 4);
}

int read_char(void *p, int byte)
{
    do
    {
        printf("%x\n", *(char *)p);
        byte--;

        p = (char *)p + 1;
    } while (p && byte);
    return 0;
}