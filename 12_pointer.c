#include <stdio.h>

void basic(void);

void const_pointer(void);
void pointer_calculation(void);

/* array and pointer */
void ary_address(void);
void ary_usage(void);

void diff_ary_pointer(void);

void two_dimension(void);
void one_dimension(void);

void pointer_of_pointer(void);
void ary_name_address(void);

void more_2D(void);
void point_2D(void);

void ary_of_pointer(void);


int main()
{
    ary_of_pointer();
    return 0;
}

void basic(void)
{
    /* & : value   ->  address
       * : address ->  value  */

    int a = 2;
    printf("address of var 'a' : %p\n", &a); // as hecadecimal

    int *p;
    p = &a; 
    printf("value in ponter 'p' : %p\n", p);
    printf("value in var 'a' : %d\n", *p);

    *p = 5;
    printf("change value of 'a' with pointer : %d\n", *p);
}

void const_pointer(void)
{
    int a;
    int b;
    const int* pa = &a;

    // *pa = 3;  // error
    a = 3;       // non error
    pa = &b;     // non error

    int* const pb = &b;
    *pb = 3;     // non error
    // pb = &a;  // error     
}

void pointer_calculation(void)
{ 
    /* (pointer + n) = (pointer + n * size of pointer type)  */
    int a;
    int *pa = &a;
    printf("value of pa : %p\n", pa);
    printf("value of (pa+1) : %p\n", pa+1);  // == pa + 4byte(size of int)
    printf("value of (pa-1) : %p\n", pa-1);  // == pa - 4byte(size of int)

    char b;
    char *pb = &b;
    printf("value of pb : %p\n", pb);
    printf("value of (pb+1) : %p\n", pb+1);  // == pb + 1byte(size of char)

    double c;
    double *pc = &c;
    printf("value of pc : %p\n", pc);
    printf("value of (pc+1) : %p\n", pc+1);  // == pc + 8byte(size of) 

    /* substitution */
    a = 3;
    int *p;
    p = pa;
    printf("value of *pa = %d\n", *pa);
    printf("value of *p = %d\n", *p);
}

void ary_address(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *parr = &arr[0];
    for (int i = 0; i < 10; i++) 
    {
        printf("address of arr[%d] : %p / value of (parr + 0) : %p", i, &arr[i], (parr+i));
        if (&arr[i] == (parr+i)) printf(" => same\n");
        else printf(" => different\n");
    }
}

void ary_usage(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *parr = arr;  // arr == &arr[0]

    printf("arr[3] = %d, *(parr+3) = %d\n", arr[3], *(parr+3));
    printf("2[arr] = %d, *(parr+2) = %d\n", 2[arr], *(parr+2));
    // a[b] == *(a + b)
}

void diff_ary_pointer(void)
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int *parr = arr;

    printf("size of arr = %d\n",  sizeof(arr));      // size of whole array
    printf("size of pointer = %d\n", sizeof(parr));  // size of a pointer
}

void two_dimension()
{
    int arr[3][3] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("address of arr[%d][%d] = %p / ", i, j, &arr[i][j]);
            printf("(*(arr + %d) + %d) = %p\n", i, j, (*(arr + i) + j));
            // *(arr + i) == arr[i]
        }
    }
    printf("\n");
    printf("size of arr[0] = %d\n", sizeof(arr[0]));
    printf("size of arr[0][0] = %d\n", sizeof(arr[0][0]));
}

void one_dimension(void)
{
    int arr[10] = {100, 98, 97, 95, 89, 76, 92, 96, 100, 99};
    int *parr = arr;
    int sum = 0;

    while ((parr - arr) <= 9)
    {
        sum += *(parr);
        parr++;
    }

    printf("Score Average = %d", sum / 10);
}

void pointer_of_pointer(void)
{
    int a = 3;
    int *pa;
    int **ppa;

    pa = &a;
    ppa = &pa;

    printf("a : %d // *pa : %d // **ppa : %d\n", a, *pa, **ppa);
    printf("&a : %p // pa : %p, // *ppa : %p\n", &a, pa, *ppa);
    printf("&pa : %p // ppa : %p\n", &pa, ppa);
}

void ary_name_address(void)
{
    int arr[3] = {1, 2, 3};
    int (*parr)[3] = &arr;   // int *parr[3] = array that has three int* elements

    printf("arr[1] : %d // parr[1] : %d \n", arr[1], (*parr)[1]);
    printf("arr : %p // parr : %p \n", arr, parr);
}

void more_2D(void)
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    printf("arr[0] : %p\n", arr[0]);            // without sizeof or &, arr[0] == address of arr[0][0]
    printf("&arr[0][0] : %p\n", &arr[0][0]);
    printf("arr[1] : %p\n", arr[1]);
    printf("&arr[1][0] : %p\n", &arr[1][0]);

    printf("total size : %d\n", sizeof(arr));
    printf("total column : %d\n", sizeof(arr[0]) / sizeof(arr[0][0]));
    printf("total row : %d\n", sizeof(arr) / sizeof(arr[0]));
}

void point_2D(void)
{
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*parr)[3];  // == one dimensional array with size 3 (when delcaring pointer we have to give "column number")

    parr = arr;
    printf("parr[1][2] : %d, arr[1][2] : %d\n", parr[1][2], arr[1][2]);
}

void ary_of_pointer(void)
{
    int *arr[3];
    int a = 1, b = 2, c = 3;
    arr[0] = &a;
    arr[1] = &b;
    arr[2] = &c;

    printf("a : %d, *arr[0] : %d\n", a, *arr[0]);
    printf("b : %d, *arr[1] : %d\n", b, *arr[1]);
    printf("c : %d, *arr[2] : %d\n", c, *arr[2]);

    printf("&a : %p, arr[0] : %p\n", &a, arr[0]);
}