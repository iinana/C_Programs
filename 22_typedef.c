#include <stdio.h>
enum { MALE, FEMALE };

struct HUMAN
{
    int gender;
    int age;
    int height;
    int weight;
};

typedef struct HUMAN Human;
void Human_print(Human h);

int add(int a, int b) { return a + b; }
typedef int (*Padd)(int, int);
typedef int Arrays[10];


int main()
{
    /* typedef keyword basic */
    Human a = {MALE, 31, 182, 75};
    Human b = {FEMALE, 27, 166, 48};

    Human_print(a);
    Human_print(b);

    /* many kinds of typedef */
    Arrays arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Padd ptr = add;

    printf("arr[3] = %d\n", arr[3]);
    printf("add(3, 5) = %d\n", ptr(3, 5));
}

void Human_print(Human h)
{
    printf("%s\n", (h.gender == MALE) ? "MALE" : "FEMALE");
    printf("AGE : %d | Height : %d | Weight : %d\n", h.age, h.height, h.weight);

    if (h.gender == MALE)
    {
        if ((h.height > 180) && (h.weight < 80)) printf("HE IS A WINNER!\n");
        else printf("HE IS A LOSER!!\n");
    }

    printf("-------------------------------------------------------------\n");
}

