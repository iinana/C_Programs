#include <stdio.h>
#include <math.h>
#include <string.h>

/* [13-3] practice num 1 */
void pass_fail(void);
void scan_score(int (*ary)[4], int row);
void order_pf(int (*ary)[4], int row);
int find_1st(int (*ary)[4], int row);

/* [13-3] practice num 2 */
void GCF(void);
int Euclidean(int ary, int n);

/* [13-3] practice num 3 */
void multiple(void);
int self_mul(int n);

int main()
{
    multiple();
    return 0;
}

/* [13-3] practice num 1 */
void pass_fail(void)
{
    int ary[5][4];
    scan_score(ary, 5);
    order_pf(ary, 5);
}

void scan_score(int (*ary)[4], int row)
{
    int tot;
    for (int i = 0; i < row; i++)
    {
        tot = 0;
        printf("[Student %d score input]\n", i+1);
        printf("Math : ");
        scanf("%d", &ary[i][0]);
        printf("Korean : ");
        scanf("%d", &ary[i][1]);
        printf("English : ");
        scanf("%d", &ary[i][2]);
        printf("\n");

        for (int j = 0; j < 3; j++) tot += ary[i][j];
        ary[i][3] = tot / 3;
    }
}

void order_pf(int (*ary)[4], int row)
{
    int tot = 0, avg, i;
    for (i = 0; i < row; i++)
    {
        tot += ary[i][3];
    }
    avg = tot / row;

    int first;
    for (i = 0; i < row; i++)
    {
        first = find_1st(ary, 5);
        printf("[Student %d] Math = %3d, Korean = %3d, English = %3d | Average = %3d | %s\n", 
                first+1, ary[first][0], ary[first][1], ary[first][2], ary[first][3], 
                (ary[first][3] > avg) ? "Pass" : "Fail");
        ary[first][3] = -1;
    }
}

int find_1st(int (*ary)[4], int row)
{
    int first = 0;
    for (int i = 1; i < row; i++)
    {
        if (ary[first][3] < ary[i][3]) first = i;
    }
    return first;
}


/* [13-3] practice num 2 */
void GCF(void)
{
    int n;
    printf("how many numbers? : ");
    scanf("%d", &n);

    int ary[n];
    printf("enter %d numbers : ", n);
    for (int i = 0; i < n; i++) scanf("%d", &ary[i]);
    
    int gcf;
    gcf = Euclidean(ary[0], ary[1]);
    for (int i = 2; i < n; i++) gcf = Euclidean(ary[i], gcf);
    
    printf("The Greatest Common Factor : %d\n", gcf);
}

int Euclidean(int a, int b)
{
    if ((a % b) == 0) return b;
    else Euclidean(b, (a % b));
}


/* [13-3] practice num 3 */
void multiple(void)
{
    int n;
    scanf("%d", &n);

    printf("multiplication 1 to %d : %d", n, self_mul(n));
}

int self_mul(int n)
{
    if (n == 1) return 1;
    else return n * self_mul(n-1);
}
