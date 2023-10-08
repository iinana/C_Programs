#include <stdio.h>

void struct_in_struct(void);
struct employee 
{
    int age;
    int salary;
};

struct company
{
    struct employee data;
    char name[10];
};


struct AA return_struct(int j);
struct AA
{
    int i;
};


/* another way to decalre sturct */
struct obj 
{
    char name[20];
    int x, y;
} Ball;
void copy_str(char *dest, char *src);
void Print_Obj_Status(struct obj OBJ);

/* easy way to initialize */
struct HUMAN
{
    int age;
    int height;
    int weight;
    int gender;
};
void Print_Status(struct HUMAN human);

/* Enum type */
enum { RED = 3, BLUE, WHITE, BLACK };


int main()
{
    struct_in_struct();

    /* function return sturct */
    struct AA a;
    a = return_struct(10);
    printf("a.i = %d\n", a.i);

    /* another way to declare sturct */
    Ball.x = 3;
    Ball.y = 4;
    copy_str(Ball.name, "RED BALL");
    Print_Obj_Status(Ball);

    /* easy way to initialize */
    struct HUMAN Adam = {31, 182, 75, 0};
    struct HUMAN Eve = {27, 166, 48, 1};

    Print_Status(Adam);
    Print_Status(Eve);

    /* enum type */
    int palette = RED;
    switch (palette)
    {
    case RED:
        printf("palette : RED\n");
        break;
    case BLUE:
        printf("palette : BLUE\n");
        break;
    case WHITE:
        printf("palette : WHITE\n");
        break;
    case BLACK:
        printf("palette : BLACK\n");
        break;
    }
    printf("BLACK = %d\n", BLACK);
    
    return 0;
}

void struct_in_struct(void)
{
    struct company Kim;
    Kim.data.age = 31;
    Kim.data.salary = 3000000;

    printf("Kim's age : %d\n", Kim.data.age);
    printf("Kim's salary : %d$/year\n", Kim.data.salary);
}

struct AA return_struct(int j)
{
    struct AA a;
    a.i = j;

    return a;
}

void copy_str(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
}

void Print_Obj_Status(struct obj OBJ)
{
    printf("Location of %s\n", OBJ.name);
    printf("( %d , %d )\n", OBJ.x, OBJ.y);
}

void Print_Status(struct HUMAN human)
{
    printf("%s\n", (human.gender == 0) ? "MALE" : "FEMALE");
    printf("AGE : %d / Height : %d / Weight : %d\n", human.age, human.height, human.weight);
    if ((human.gender == 0) && (human.height >= 180)) printf("HE IS A WINNER!!\n");
    else if (human.gender == 0) printf("HE IS A LOSER!!\n");
    printf("-------------------------------------------------------\n");
}