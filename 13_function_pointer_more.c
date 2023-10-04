#include <stdio.h>

/* swap the variable which pointers are pointing */
void pswap(int **ppa, int **ppb);

/* muti dimensional array as an argument */
void add1_elem(int (*pary)[2], int row);  // int (*pointer)[num of columns], int (num of rows)
void multi_dimen(int ary[][2], int row);
void high_dimen(int (*pary)[2][3][4], int row);


int main()
{
    /* swap the variable which pointers are pointing */
    int a, b;
    int *pa = &a, *pb = &b;

    printf("address value pointed by pa : %p\n", pa);
    printf("address of pa : %p\n", &pa);

    printf("address value pointed by pb : %p\n", pb);
    printf("address of pb : %p\n", &pb);

    pswap(&pa, &pb);

    printf("address value pointed by pa : %p\n", pa);
    printf("address of pa : %p\n", &pa);

    printf("address value pointed by pb : %p\n", pb);
    printf("address of pb : %p\n", &pb);
    printf("\n");


    /* function gets two dimensional array as an argument */
    int ary1[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++) scanf("%d", &ary1[i][j]);
    }
    add1_elem(ary1, 3);
    multi_dimen(ary1, 3);
    printf("\n");

    /* function gets high dimensional array as an argument */
    int ary2[3][2][3][4] = {{{{0, 0, 0, 0}, {1, 1, 1, 1}, {2, 2, 2, 2}}, {{3, 3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5}}}, 
                           {{{6, 6, 6, 6}, {7, 7, 7, 7}, {8, 8, 8, 8}}, {{9, 9, 9, 9}, {0, 0, 0, 0}, {1, 1, 1, 1}}}, 
                           {{{2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}}, {{5, 5, 5, 5}, {6, 6, 6, 6}, {7, 7, 7, 7}}}};
    high_dimen(ary2, 3);
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int r = 0; r < 4; r++) printf("%d ", ary2[i][j][k][r]++);
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }    
}

void pswap(int **ppa, int **ppb)
{
    printf("-------- calling --------\n");
    printf("address value pointed by ppa : %p\n", ppa);
    printf("address value pointed by ppb : %p\n", ppb);

    int *temp = *ppa;
    *ppa = *ppb;
    *ppb = temp;

    printf("-------- calling --------\n");
}

void add1_elem(int (*pary)[2], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++) pary[i][j]++;
    }
}

void multi_dimen(int ary[][2], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++) printf("ary[%d][%d] = %d\n", i, j, ary[i][j]);
    }
}

void high_dimen(int (*pary)[2][3][4], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int r = 0; r < 4; r++) pary[i][j][k][r]++;
            }
        }
    }
}