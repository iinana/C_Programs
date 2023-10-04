#include <stdio.h>

/* For Statement */
void for_statement(void);
void ex_sum(void);
void ex_score(void);

void break_stat(void);
void continue_stat(void);

void for_in_for(void);

/* While Statement */
void while_stat(void);
void do_while(void);


int main()
{
    do_while();
    return 0;
}

void for_statement(void)
{
    for (int i = 0; i < 20; i++) printf("number : %d\n", i);
}

void ex_sum(void)
{
    int tot = 0;
    for (int i = 1; i <20; i++) tot += i;
    printf("summation from 1 to 19: %d", tot);
}

void ex_score(void)
{
    int n;
    double score, tot;
    printf("how many subjects?: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Subject%d : ", i);
        scanf("%lf", &score);
        tot += score;
    }
    printf("Average of Scores : %.2f", tot/n);
}

void break_stat(void)
{
    int answer = 3;
    int guess;
    
    printf("guess the number which computer thought\n");
    for (;;)
    {
        scanf("%d", &guess);

        if (guess == answer)
        {
            printf("Correct");
            break;
        }
        else printf("Wrong\n");
    }
}

void continue_stat(void)
{
    for (int i = 1; i < 100; i++)
    {
        if (i % 5 == 0) continue;
        printf("%d ", i);
    }
}

void for_in_for(void)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++) printf("%d x %d = %d\n", i, j, i*j);
    }
}

void while_stat(void)
{
    int i = 0, sum = 0;

    while (i < 100)
    {
        i++;
        sum += i;
    }
    printf("summation from 1 to 100: %d", sum);
}

void do_while(void)
{
    int i = 1, sum = 0;
    do
    {
        sum += i;
        i++;
    } while (i <= 100);
    printf("sum = %d", sum);
}