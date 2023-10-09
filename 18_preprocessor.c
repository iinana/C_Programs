#include <stdio.h>

/* 1. define */
#define VAR 10

/* 2. ifdef, endif */
// #define A
// #ifdef A
// printf("AAA\n");
// #endif
// #ifdef B
// printf("BBB\n");
// #endif;

#define CALCULATOR_MODEL_1
#ifdef CALCULATOR_MODEL_1
float var1, var2;
#endif
#ifdef CALCULATOR_MODEL_2
double var1, var2;
#endif



int main()
{
    char arr[VAR] = "hi";
    printf("arr using #define : %s\n", arr);
    return 0;
}