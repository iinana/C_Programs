#include <stdio.h>
#include <stdlib.h>

int *append(int *origin, int size, int add);

int main()
{
    int size;
    printf("size of array : ");
    scanf("%d", &size);

    int *ary = (int*)malloc(sizeof(int) * size);
    printf("enter %d integers -----------------------------\n", size);
    for (int i = 0; i < size; i++) scanf("%d", &ary[i]);

    int add;
    printf("additional size needed : ");
    scanf("%d", &add);
    int *new_ary = append(ary, size, add);

    printf("appended ary :");
    for (int i = 0; i < (size + add); i++) printf(" %d", new_ary[i]);
    printf("\n");
}

int *append(int *origin, int size, int add)
{
    int *ary = (int *)malloc(sizeof(int) * (size + add));

    int i;
    for (i = 0; i < size; i++) ary[i] = origin[i];

    printf("enter %d more integers -------------------------\n", add);
    for (i = size; i < (size+add); i++) scanf("%d", &ary[i]);

    return ary;
}