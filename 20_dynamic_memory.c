#include <stdio.h>
#include <stdlib.h>

void malloc_basic(void);
void use_dyn_memory(void);

/* two ways for dynamic memory allocation of two dimensional array */
void use_pointer_ary(void);  // way1 : using pointer array
void prac_way1(void);
void get_average(int **arr, int numStudent, int numSubject);

void real_2D_ary(void);  // way2 : allocate memory with two dimensional size and then refer to it by two dimensional pointer
void print_ary(int width, int (*arr)[width], int height);  // width should come first
void add_one(int width, int (*arr)[width], int height);
void prac_way2(void);
void get_average2(int numSubject, int (*score)[numSubject], int numStudent);


int main()
{
    prac_way2();
    return 0;
}

void malloc_basic(void)
{
    int SizeOfArray;
    int *arr;

    printf("number of elemnet of array : ");
    scanf("%d", &SizeOfArray);

    arr = (int *)malloc(sizeof(int) * SizeOfArray);
    // malloc() func : return the void type starting memory with the size of argument
    free(arr);
    // free() : prevent memory leak
}

void use_dyn_memory(void)
{
    int *score;
    int num, tot = 0;

    printf("number of students : ");
    scanf("%d", &num);

    score = (int*)malloc(sizeof(int) * num);
    free(score);

    for (int i = 0; i < num; i++)
    {
        printf("Score of Studnet %d : ", i);
        scanf("%d", &score[i]);
        tot += score[i];
    }

    printf("Average of Total Students : %d\n", tot/num);
}

void use_pointer_ary(void)
{
    int x, y;
    int **arr;

    printf("We will make arr[x][y]\n");
    scanf("%d%d", &x, &y);

    arr = (int**)malloc(sizeof(int *) * x);
    for (int i = 0; i < x; i++) arr[i] = (int *)malloc(sizeof(int) * y);
    printf("complete\n");

    for (int i = 0; i < x; i++) free(arr[i]);
    free(arr);
}

void prac_way1(void)
{
    int sub, stu;
    int **score;
    int x, y;

    printf("Number of Subjects : ");
    scanf("%d", &sub);
    printf("Number of Students : ");
    scanf("%d", &stu);

    score = (int**)malloc(sizeof(int*) * sub);
    for (x = 0; x < sub; x++) score[x] = (int*)malloc(sizeof(int) * stu);

    for (x = 0; x < sub; x++)
    {
        printf("Subject %d score -----------\n", x);
        for (y = 0; y < stu; y++)
        {
            printf("Student %d Score : ", y);
            scanf("%d", &score[x][y]);
        }
    }

    get_average(score, stu, sub);

    for (x = 0; x < sub; x++) free(score[x]);
    free(score);
}

void get_average(int **score, int numStudent, int numSubject)
{
    int x, y;
    int tot = 0;
    for (x = 0; x < numSubject; x++)
    {
        tot = 0;
        for (y = 0; y < numStudent; y++) tot+= score[x][y];
        printf("Subject %d Average Score : %d\n", x, tot/numStudent);
    }
}


void real_2D_ary(void)
{
    int width, height;
    printf("Size of Array Row : ");
    scanf("%d", &width);
    printf("Size of Array Column : ");
    scanf("%d", &height);

    int (*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));

    int x, y;
    for (x = 0; x < height; x++)
    {
        for (y = 0; y < width; y++) scanf("%d", &arr[x][y]);
    }

    printf("----------------- ARRAY -----------------\n");
    print_ary(width, arr, height);
    printf("---------------- ADD ONE ----------------\n");
    add_one(width, arr, height);
    print_ary(width, arr, height);

    free(arr);
}

void print_ary(int width, int (*arr)[width], int height)  // width should come first
{
    int x, y;
    for (x = 0; x < height; x++)
    {
        for (y = 0; y < width; y++) printf("%d ", arr[x][y]);
        printf("\n");
    }
}

void add_one(int width, int (*arr)[width], int height)
{
    int x, y;
    for (x = 0; x < height; x++)
    {
        for (y = 0; y < width; y++) ++arr[x][y];
    }
}

void prac_way2(void)
{
    int sub, stu;
    int x, y;

    printf("Number of Subjects : ");
    scanf("%d", &sub);
    printf("Number of Students : ");
    scanf("%d", &stu);

    int (*score)[stu];
    score  = (int(*)[stu])malloc(sizeof(int) * sub * stu);

    for (x = 0; x < sub; x++)
    {
        printf("Subject %d score -----------\n", x);
        for (y = 0; y < stu; y++)
        {
            printf("Student %d Score : ", y);
            scanf("%d", &score[x][y]);
        }
    }

    get_average2(stu, score, sub);

    free(score);
}

void get_average2(int numStudent, int (*score)[numStudent], int numSubject)
{
    int x, y;
    int tot = 0;
    for (x = 0; x < numSubject; x++)
    {
        tot = 0;
        for (y = 0; y < numStudent; y++) tot+= score[x][y];
        printf("Subject %d Average Score : %d\n", x, tot/numStudent);
    }
}
