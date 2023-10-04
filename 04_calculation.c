#include <stdio.h>

/* operator */
void arithmetic_oper(void);
void assignment_oper(void);
void bit_oper(void);


int main()
{
    bit_oper();
    return 0;
}

void arithmetic_oper()
{
    int a = 10, b =3;
    printf("a + b = %d\n", a+b);
    printf("a - b = %d\n", a-b);
    printf("a * b = %d\n", a*b);
    printf("a / b = %d\n", a/b);
    printf("a %% b = %d\n", a%b);


    /* caution at division */
    // printf("a / b = %f\n", a/b);  // error
    int c = 10;
    double d = 3;
    printf("c / d = %f\n", c/d); // non-error (arithmetic conversion: compiler change type of all the vars to bigger one) 
}

void assignment_oper(void)
{
    int a = 3;
    a = a + 3;
    printf("a = %d\n", a);

    /* how to plus 1 to a */
    a = a + 1;          // basic way
    printf("%d ", a);
    a++;                // prifix increase oper
    printf("%d ", a);
    ++a;                // postfix increase oper
    printf("%d ", a);
    a += 1;             // complex assignment
    printf("%d \n", a);

    /* prefix and postfix */
    int b = 0;
    printf("b++ : %d\n", ++b); // prefix
    b = 0;
    printf("++b : %d\n", b++);
    printf("%d\n", b);
}

void bit_oper(void)
{
    int a = 0xAF;  // bit: 10101111
    int b = 0xB5;  // bit: 10110101

    /* AND oper (&) : Both first bit & second bit are '1' -> output '1' */
    printf("%x\n", a & b);  // a & b = 10100101

    /* OR oper (|): Either first bit | second bit is '1' -> output '1' */
    printf("%x\n", a | b);  // a | b = 10111111

    /* XOR oper (^): First & second bit are different -> output '1' */
    printf("%x\n", a ^ b);  // a ^ b = 00011010

    /* Inversion oper (~): 1->0 and 0->1 */
    printf("%x\n", ~a);  // ~a = 1...1 11111111 01010000

    /* Shift oper (<<, >>): shift the bit to left/right (and 0 at the blank) */
    printf("%x\n", a << 2);  // a << 2 = 1010111100
    printf("%x\n", b >> 3);  // b >> 3 = 00010110

}