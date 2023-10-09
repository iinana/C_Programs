#include <stdio.h>
#include <stdlib.h>

void input_score(int stu, int sub, int (*score)[sub]);
int get_avg(int *student, int sub);
int get_rank(int *avg, int stu, int x);

int main()
{
    int stu, sub;
    printf("Number of Student : ");
    scanf("%d", &stu);
    printf("Number of Subject : ");
    scanf("%d", &sub);

    // score[stu][sub]
    int (*score)[sub] = (int(*)[sub])malloc(sizeof(int*) * sub * stu);

    input_score(stu, sub, score);

    int *avg = (int *)malloc(sizeof(int) * stu);
    for (int x = 0; x < stu; x++) avg[x] = get_avg(score[x], sub);

    for (int x = 0; x < stu; x++) printf("Average and Rank of Student %d : %3d, %2d\n", x, avg[x], get_rank(avg, stu, x));
}

void input_score(int stu, int sub, int (*score)[sub])
{
    for (int x = 0; x < stu; x++)
    {
        printf("Student %d ---------------------\n", x);
        for (int y = 0; y < sub; y++) 
        {
            printf("Subject %d Score : ", y);
            scanf("%d", &score[x][y]);
        }
    }
}

int get_avg(int *student, int sub)
{
    int tot = 0;
    for (int i = 0; i < sub; i++) tot += student[i];
    return tot / sub;
}

int get_rank(int *avg, int stu, int x)
{
    int rank = 1;
    for (int i = 0; i < stu; i++)
    {
        if (i == x) continue;
        if (avg[i] > avg[x]) rank++;
    }
    return rank;
}