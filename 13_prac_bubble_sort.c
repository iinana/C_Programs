#include <stdio.h>

void scan_score(int *avg, int len);
void Bubble_sort(int *arr, int n);
void swap(int *arr);
void pass_or_fail(int *arr, int n, int tot_avg);


int main()
{
    int avg[5];
    const int len = 5;
    scan_score(avg, len);

    int tot_avg, tot = 0;
    for (int i = 0; i < len; i++) tot += avg[i];
    tot_avg = tot / len;

    Bubble_sort(avg, 5);
    pass_or_fail(avg, 5, tot_avg);

}

void scan_score(int *avg, int len)
{
    int mat, kor, eng;
    for (int i = 0; i < len; i++)
    {
        printf("[Student %d score input]\n", i+1);
        printf("Math : ");
        scanf("%d", &mat);
        printf("Korean : ");
        scanf("%d", &kor);
        printf("English : ");
        scanf("%d", &eng);
        printf("\n");

        avg[i] = (mat + kor + eng) / 3;
    }
}

void Bubble_sort(int *arr, int n)
{
    int temp;
    n--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            if (arr[j] < arr[j+1]) swap(&arr[j]);
        }
    }
}

void swap(int *arr)
{
    int temp;
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

void pass_or_fail(int *avg, int n, int tot_avg)
{
    for (int i = 0; i < n; i++)
    {
        printf("avg : %3d => ", avg[i]);
        if (avg[i] > tot_avg) printf("Pass\n");
        else printf("Fail\n");
    }
}