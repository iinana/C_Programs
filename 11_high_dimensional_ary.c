#include <stdio.h>

/* two dimensional array */
void basic(void);
void ex_score(void);
void extra(void);

/* other high dimensional array */
void three_dimension(void);
void four_dimension(void);

int main()
{
    three_dimension();
    return 0;
}

void basic(void)
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("second row, third column of arr : %d\n", arr[1][2]);
    printf("first row, second column of arr : %d\n", arr[0][1]);
}

void ex_score(void)
{
    int score[3][2];
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            if (k == 0) printf("English Score of Student %d : ", (i+1));
            else printf("Math Score of Stduent %d : ", (i+1));
            scanf("%d", &score[i][k]);
        }
    }

    for (int i = 0; i < 3; i++) printf("Studnet %d's English Score: %3d, Math Score: %3d\n", (i+1), score[i][0], score[i][1]);
}

void extra(void)
{
    int arr[][2] = {{1, 2}, {3, 4}, {5, 6}};  // can leave [row] empty (not [column]!!)
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 2; k++) printf("%d ", arr[i][k]);
        printf("\n");
    }
}

void three_dimension(void)
{
    int arr[2][3][4] = {{{0, 0, 0, 0}, {1, 1, 1, 1}, {2, 2, 2, 2}},
                        {{3, 3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5}}};

    for (int z = 0; z < 2; z++)
    {
        printf("z = %d\n", z);
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                printf("%d ", arr[z][x][y]);
            }
            printf("\n");
        }
        printf("\n");
    }
}