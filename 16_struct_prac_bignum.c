#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define LIMIT 100

struct BigNum
{
    int i_digit[LIMIT];   // integer part
    int d_digit[LIMIT];   // decimal part
    int i_total_digit;    // digit of integer
    int d_total_digit;    // digit of decimal
    char sign;            // 0 = positive & 1 = negative
};

/* 1. add function */
struct BigNum add(struct BigNum *a, struct BigNum *b);
void add_int(struct BigNum *a, struct BigNum *b, struct BigNum *res);
void add_dec(struct BigNum *a, struct BigNum *b, struct BigNum *res);
void up_int(int *num, int *len);
void up_dec(int *dec, int *len, int *inte, int *int_len);

/* 2. subtraction funciton */
struct BigNum sub(struct BigNum *a, struct BigNum *b);
void sub_int(struct BigNum *a, struct BigNum *b, struct BigNum *res);
int compare(struct BigNum a, struct BigNum b);
void sub_dec(struct BigNum *a, struct BigNum *b, struct BigNum *res);
void down_int(struct BigNum *num);
void down_dec(struct BigNum *num);

/* 3. multiple function */
struct BigNum mul(struct BigNum *a, struct BigNum *b);
void mul_each(struct BigNum *a, struct BigNum *b, struct BigNum *res, int *m);
void conv_to_BigNum(struct BigNum *res, int *m);

/* 4. divide function */
struct BigNum divi(struct BigNum a, struct BigNum b);
struct BigNum make_temp(struct BigNum a, struct BigNum b, int loc, int len);
int part_div(struct BigNum *a, struct BigNum *b, struct BigNum *temp);
void save_res(struct BigNum *res, int loc, int count);
void save_int_part(struct BigNum *a, struct BigNum temp, int loc, int diff);
void save_dec_part(struct BigNum *a, struct BigNum temp, int loc);


void print_BigNum(struct BigNum num);


int main()
{
    struct BigNum a, b;

    a.i_digit[99] = 9;
    a.i_digit[98] = 4;
    a.i_digit[97] = 7;
    a.i_digit[96] = 6;
    a.d_digit[0] = 8;
    a.d_digit[1] = 4;
    a.d_digit[2] = 6;
    a.d_digit[3] = 1;
    a.d_digit[4] = 8;
    a.i_total_digit = 4;
    a.d_total_digit = 5;
    a.sign = 1;

    b.i_digit[99] = 0;
    b.i_digit[98] = 2;
    b.i_digit[97] = 0;
    b.i_digit[96] = 5;
    b.i_digit[95] = 9;
    b.d_digit[0] = 2;
    b.d_digit[1] = 7;
    b.d_digit[2] = 3;
    b.d_digit[3] = 9;
    b.i_total_digit = 2;
    b.d_total_digit = 4;
    b.sign = 0;

    struct BigNum res = divi(a, b);
    print_BigNum(res);
    printf("%llf\n", 6749.84618/20.2739);
    //printf("%llf\n", 49.846*20.27);
    return 0;
}


/* sum and subtraction */
struct BigNum add(struct BigNum *a, struct BigNum *b)
{
    struct BigNum res;

    if (a->sign == b->sign)
    {
        add_int(a, b, &res);
        assert(res.i_total_digit <= 100);
        
        add_dec(a, b, &res);
        assert(res.d_total_digit <= 100);

        res.sign = a->sign;
    }
    else if (a->sign == 0)
    {
        b->sign = 0;
        res = sub(a, b);
    }
    else 
    {
        a->sign = 0;
        res = sub(b, a);
    }
    return res;
}

struct BigNum sub(struct BigNum *a, struct BigNum *b)
{
    struct BigNum res;

    if ((a->sign == 0) && (b->sign == 0))
    {
        res.sign = compare(*a, *b);
        if (res.sign == 1)
        {
            struct BigNum *temp;
            temp = a;
            a = b;
            b = temp;
        } 

        sub_int(a, b, &res);
        assert(res.i_total_digit <= 100);
        
        sub_dec(a, b, &res);
        assert(res.d_total_digit <= 100);
    }
    else if ((a->sign == 1) && (b->sign == 1))
    {
        a->sign = 0;
        b->sign = 0;
        res = sub(b, a);
    }
    else if (a->sign == 0)
    {
        b->sign = 0;
        res = add(a, b);
    }
    else
    {
        a->sign = 0;
        res = add(a, b);
    }

    return res;
}

int compare(struct BigNum a, struct BigNum b)
{
    /* (a > b) => return 0  |  (a < b) => return 1 */
    int lena = a.i_total_digit;
    int lenb = b.i_total_digit; 

    if (lena > lenb) return 0;
    else if (lena < lenb) return 1;
    else
    {
        do
        {
            if (a.i_digit[LIMIT-lena] > b.i_digit[LIMIT-lena]) return 0;
            else if (a.i_digit[LIMIT-lena] < b.i_digit[LIMIT-lena]) return 1;
            lena--;
        }
        while (lena >= 0);
    }

    lena = a.d_total_digit;
    lenb = b.d_total_digit;
    int i = 0;

    do
    {
        if (a.d_digit[i] > b.d_digit[i]) return 0;
        else if (a.d_digit[i] < b.d_digit[i]) return 1;
        i++;
    }
    while ((i < lena) && (i < lenb) && (a.d_digit[i] == b.d_digit[i]));

    if (i < lena) return 0;
    else return 1;
}


void add_int(struct BigNum *a, struct BigNum *b, struct BigNum *res)
{
    int i, j;
    struct BigNum *max, *min;

    /* find longer one among a & b */
    if (a->i_total_digit > b->i_total_digit)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }

    res->i_total_digit = max->i_total_digit;  // length of res is length of longer one

    /* add */
    for (i = 1; i <= (min->i_total_digit); i++) res->i_digit[LIMIT-i] = max->i_digit[LIMIT-i] + min->i_digit[LIMIT-i];
    for (j = (min->i_total_digit + 1); j <= (max->i_total_digit); j++) res->i_digit[LIMIT-j] = max->i_digit[LIMIT-j];

    up_int(res->i_digit, &(res->i_total_digit));
}

void add_dec(struct BigNum *a, struct BigNum *b, struct BigNum *res)
{
    int i, j;
    struct BigNum *max, *min;

    /* find longer one among a & b */
    if (a->d_total_digit > b->d_total_digit)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    res->d_total_digit = max->d_total_digit;

    /* add */
    for (i = 0; i < (min->d_total_digit); i++) res->d_digit[i] = max->d_digit[i] + min->d_digit[i];
    for (j = i; j < (max->d_total_digit); j++) res->d_digit[j] = max->d_digit[j];

    up_dec(res->d_digit, &(res->d_total_digit), res->i_digit, &(res->i_total_digit));
}

void up_int(int *num, int *len)
{
    int up;
    for (int i = 1; i <= *len; i++)
    {
        up = num[LIMIT-i] / 10;
        if (up > 0)
        {
            num[LIMIT-i] -= (up * 10);
            if (i == *len) 
            {
                ++*len;
                num[LIMIT - *len] = up;
            }
            else num[LIMIT - i - 1] += up;
        }
    }
}

void up_dec(int *dec, int *len, int *inte, int *int_len)
{
    int up;
    for (int i = (*len - 1); i >= 0; i--)
    {
        up = dec[i] / 10;
        if (up > 0)
        {
            dec[i] -= (up * 10);
            if (i == 0)
            {
                inte[99] += up;
                if (inte[99] >= 10) up_int(inte, int_len);
            }
            else dec[i-1] += up;
        }
    }
    
    while (dec[*len - 1] == 0) --*len;
}

void sub_int(struct BigNum *a, struct BigNum *b, struct BigNum *res)
{
    int i, j;
    for (i = 1; i <= b->i_total_digit; i++) res->i_digit[LIMIT-i] = a->i_digit[LIMIT-i] - b->i_digit[LIMIT-i];
    for (j = i; j <= a->i_total_digit; j++) res->i_digit[LIMIT-j] = a->i_digit[LIMIT-j];
    res->i_total_digit = a->i_total_digit;

    down_int(res);
}

void sub_dec(struct BigNum *a, struct BigNum *b, struct BigNum *res)
{
    int i;
    int diff = a->d_total_digit - b->d_total_digit;
    if (diff > 0)
    {
        for (i = b->d_total_digit; i < (b->d_total_digit + diff); i++) b->d_digit[i] = 0;
        res->d_total_digit = a->d_total_digit;
    }
    else if (diff < 0)
    {
        for (i = a->d_total_digit; i < (a->d_total_digit - diff); i++) a->d_digit[i] = 0;
        res->d_total_digit = b->d_total_digit;
    }
    else res->d_total_digit = b->d_total_digit;

    for (i = (res->d_total_digit - 1); i >= 0; i--) res->d_digit[i] = a->d_digit[i] - b->d_digit[i];
    down_dec(res);
}

void down_int(struct BigNum *num)
{
    int len = num->i_total_digit;
    for (int i = 1; i < len; i++)
    {
        if (num->i_digit[LIMIT-i] < 0)
        {
            num->i_digit[LIMIT-i] += 10;
            --(num->i_digit[LIMIT-i-1]);
        }       
    }
    
    while (num->i_digit[LIMIT - len] == 0) len--;
    num->i_total_digit = len;
}

void down_dec(struct BigNum *num)
{
    for (int i = (num->d_total_digit - 1); i >= 0; i--) 
    {
        if (num->d_digit[i] < 0)
        {
            if (i == 0)
            {
                --(num->i_digit[LIMIT-1]);
                if (num->i_digit[LIMIT-1] < 0) down_int(num);
            }
            else --(num->d_digit[i-1]);
            num->d_digit[i] += 10;
        }
    }
}


/* multiplication */
struct BigNum mul(struct BigNum *a, struct BigNum *b)
{
    struct BigNum res;
    /* sign of res */
    if (a->sign == b->sign) res.sign = 0;
    else res.sign = 1;

    /* confirm d_total_degit of res */

    res.d_total_digit = a->d_total_digit + b->d_total_digit;
    assert(res.d_total_digit <= 100);

    /* multiple */
    int m[100] = { 0, };
    mul_each(a, b, &res, m);

    conv_to_BigNum(&res, m);

    return res;
}

void mul_each(struct BigNum *a, struct BigNum *b, struct BigNum *res, int *m)
{
    int dlen_a = a->d_total_digit;
    int dlen_b = b->d_total_digit;
    int ilen_a = a->i_total_digit;
    int ilen_b = b->i_total_digit;

    int i, j;
    int loc1 = 0, loc2 = 0;

    for (i = (dlen_b-1); i >= 0; i--)
    {
        loc2 = 0;
        for (j = (dlen_a-1); j >= 0; j--) 
        {
            m[loc1+loc2] += b->d_digit[i] * a->d_digit[j];
            loc2++;
        }
        for (j = 1; j <= ilen_a; j++) 
        {
            m[loc1+loc2] += b->d_digit[i] * a->i_digit[LIMIT-j];
            loc2++;
        }
        loc1++;
    }
    for (i = 1; i <= ilen_b; i++)
    {
        loc2 = 0;
        for (j = (dlen_a-1); j >= 0; j--) 
        {
            m[loc1+loc2] += b->i_digit[LIMIT-i] * a->d_digit[j];
            loc2++;
        }
        for (j = 1; j <= ilen_a; j++) 
        {
            m[loc1+loc2] += b->i_digit[LIMIT-i] * a->i_digit[LIMIT-j];
            loc2++;
        }
        loc1++;
    }

    res->i_total_digit = loc1 + loc2 - res->d_total_digit;
}

void conv_to_BigNum(struct BigNum *res, int *m)
{
    int i, j;
    int len = res->d_total_digit;
    for (i = 0; i < res->d_total_digit; i++)
    {
        len--;
        res->d_digit[len]= m[i];
    }
    for (j = 1; j <= res->i_total_digit; j++)
    {
        res->i_digit[LIMIT-j] = m[i];
        i++;
    }
    up_int(res->i_digit, &res->i_total_digit);
    up_dec(res->d_digit, &res->d_total_digit, res->i_digit, &res->i_total_digit);
}


/* division */
struct BigNum divi(struct BigNum a, struct BigNum b)
{
    struct BigNum res;
    res.i_total_digit = 0;
    res.d_total_digit = 0;
    int i, j;

    /* sign of res */
    if (a.sign == b.sign) res.sign = 0;
    else res.sign = 1;
    a.sign = 0;
    b.sign = 0;

    int loc = 0, len, count;
    int diff = -1;
    struct BigNum temp;

    while (res.d_total_digit < 100)
    {
        if ((len == 2) && (diff == 0)) len = b.i_total_digit;
        else if ((len == 3) && (diff == 1)) len = b.i_total_digit;
        else len = b.i_total_digit - 1; 

        if (a.i_total_digit > 0) loc = a.i_total_digit - len + 1;
        else loc += (1-len);

        do
        {
            len++;
            loc--;
            
            temp = make_temp(a, b, loc, len);
            count = part_div(&a, &b, &temp);

            if ((len > (a.i_total_digit+a.d_total_digit)) || (abs(loc) >= 100)) return res;

            save_res(&res, loc, count);
        } while (count == 0);

        diff = len - temp.i_total_digit;
        save_int_part(&a, temp, loc, diff);
        save_dec_part(&a, temp, loc);
    }
    return res;
}

struct BigNum make_temp(struct BigNum a, struct BigNum b, int loc, int len)
{
    struct BigNum temp;
    int i;

    temp.i_total_digit = len;
    temp.d_total_digit = (a.i_total_digit + a.d_total_digit) - len;
    if (loc < 0) temp.d_total_digit += (loc - 1);

    temp.sign = 0;

    int temp_loc = loc;
    for (i = 1; i <= temp.i_total_digit; i++)
    {
        if (temp_loc > 0) temp.i_digit[LIMIT-i] = a.i_digit[LIMIT-temp_loc];
        else temp.i_digit[LIMIT-i] = a.d_digit[abs(temp_loc)];
        temp_loc++;
    }

    for (i = 0; i < temp.d_total_digit; i++)
    {
        loc--;
        if (loc > 0) temp.d_digit[i] = a.i_digit[LIMIT-loc];
        else temp.d_digit[i] = a.d_digit[abs(loc)];  
    }

    return temp;
}

int part_div(struct BigNum *a, struct BigNum *b, struct BigNum *temp)
{
    int count = 0;

    while (compare(*temp, *b) == 0)  // temp > b
    {
        *temp = sub(temp, b);
        count++;
    }

    return count;
}

void save_res(struct BigNum *res, int loc, int count)
{
    printf("loc = %d, count = %d\n", loc, count);
    if (loc > 0) 
    {
        res->i_digit[LIMIT-loc] = count;
        if (loc > res->i_total_digit) res->i_total_digit = loc;
    }
    else 
    {
        int temp_loc = abs(loc);
        res->d_digit[temp_loc] = count;
        if ((temp_loc+1) > res->d_total_digit) res->d_total_digit = temp_loc + 1;
    }
}

void save_int_part(struct BigNum *a, struct BigNum temp, int loc, int diff)
{
    int i;
    for (i = 1; i <= temp.i_total_digit; i++)
    {
        if (loc > 0) a->i_digit[LIMIT-loc] = temp.i_digit[LIMIT-i];
        else a->d_digit[abs(loc)] = temp.i_digit[LIMIT-i];
        loc++;
    }
    while (diff > 0)
    {
        if (loc > 0) 
        {
            a->i_digit[LIMIT-loc] = temp.i_digit[LIMIT-i];
            --(a->i_total_digit);
        }
        else a->d_digit[abs(loc)] = temp.i_digit[LIMIT-i];
        loc++;
        diff--;
    }
}

void save_dec_part(struct BigNum *a, struct BigNum temp, int loc)
{
    int i;
    for (i = 0; i < temp.d_total_digit; i++)
    {
        loc--;
        if (loc > 0) a->i_digit[LIMIT-loc] = temp.d_digit[i];
        else a->d_digit[abs(loc)] = temp.d_digit[i];
    }
    
    if ((loc < 0) && (abs(loc) >= a->d_total_digit)) a->d_total_digit = abs(--loc);
}

void print_BigNum(struct BigNum num)
{
    if (num.sign == -1)
    {
        printf("0.0\n");
        return;
    }

    int i;
    if (num.sign == 1) printf("-");
    for (i = (LIMIT - num.i_total_digit); i < LIMIT; i++) printf("%d", num.i_digit[i]);
    printf(".");
    for (i = 0; i < num.d_total_digit; i++) printf("%d", num.d_digit[i]);
    printf("\n");
}