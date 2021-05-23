#include <stdio.h>
#include <cs50.h>

// Function declaration
int lenHelper(long x);
int thirtenlng(long x);
int splittwo_sum(int x);
int fiftenlng(long x);
int sixtenlng(long x);


//declare input
int a1;
int a2;
int a3;
int a4;
int a5;
int a6;
int a7;
int a8;
int a9;
int a10;
int a11;
int a12;
int a13;
int a14;
int a15;
int a16;
long x2;
long x3;
long x4;
long x5;
long x6;
long x7;
long x8;
long x9;
long x10;
long x11;
long x12;
long x13;
long x14;
long x15;
long x16;

int main(void)
{
    long num = get_long("Specify the credit card number : \n");
    int p=lenHelper(num);
    //printf("card number length : %d\n",p);

    // For VISA
    if (p == 13)
    {
        int onedigit = num/1000000000000;

        //printf("first 1 digit : %d\n",onedigit);
        if(onedigit==4)
        {
           int zerocheck = thirtenlng(num);

            if(zerocheck == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
           printf("INVALID\n");
        }
    }

    // For American Express
    else if (p == 15)
    {
        int twodigit = num/10000000000000;
        //printf("first 2 digit : %d\n",twodigit);

        if( twodigit == 34 || twodigit == 37 )
        {
           int zerocheck = fiftenlng(num);

            if(zerocheck == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
           printf("INVALID\n");
        }
    }

    // For VISA and Mastercard
    else if (p == 16)
    {
        int twodigit = num/100000000000000;
        //printf("first 2 digit : %d\n",twodigit);
        int onedigit = num/1000000000000000;
        //printf("first 1 digit : %d\n",onedigit);

        if( twodigit >= 51 && twodigit <= 55  )
        {
           int zerocheck=sixtenlng(num);

            if(zerocheck == 0)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        } else if(onedigit == 4)
        {
            int zerocheck=sixtenlng(num);

            if(zerocheck == 0)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
         else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}



// Function to test if the number yields a 0 in last digit or not afte the following operations:
    //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    //Add the sum to the sum of the digits that weren’t multiplied by 2
    //If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
//int Zero_or_not(long num )


int lenHelper(long x)
{
    if (x >= 1000000000000000 && x <= 9999999999999999 ) return 16;
    if (x >= 100000000000000 && x <= 999999999999999)  return 15;
    if (x >= 10000000000000 && x <= 99999999999999 )   return 14;
    if (x >= 1000000000000 && x <= 9999999999999 )    return 13;
    if (x >= 1000 && x <= 9999)    return 4;
    return 1;
}

//Create function to check Luhn’s Algorithm result for 13 digit credit card
int thirtenlng(long x)
{

a1 = x % 10;
x2 = x % 100;
x3 = x % 1000;
x4 = x % 10000;
x5 = x % 100000;
x6 = x % 1000000;
x7 = x % 10000000;
x8 = x % 100000000;
x9 = x % 1000000000;
x10 = x % 10000000000;
x11 = x % 100000000000;
x12 = x % 1000000000000;

a2 = (x2 - a1) / 10;
a3 = (x3 - x2) / 100;
a4 = (x4 - x3) / 1000;
a5 = (x5 - x4) / 10000;
a6 = (x6 - x5) / 100000;
a7 = (x7 - x6) / 1000000;
a8 = (x8 - x7) / 10000000;
a9 = (x9 - x8) / 100000000;
a10 = (x10 - x9) / 1000000000;
a11 = (x11 - x10) / 10000000000;
a12 = (x12 - x11) / 100000000000;
a13 = (x - x12) / 1000000000000;

int sum1 = splittwo_sum(a12*2) + splittwo_sum(a10*2) + splittwo_sum(a8*2) + splittwo_sum(a6*2) + splittwo_sum(a4*2) + splittwo_sum(a2*2);
int sum2= a13 + a11 + a9 + a7 + a5 + a3 +a1;
int sum_tot = sum1 + sum2;
int test = sum_tot%10;
//printf("tottal sum : %d %d %d\n",sum_tot, sum2, sum1);
//printf("all num : %d %d %d %d %d %d %d %d %d %d %d %d %d %ld %ld %ld\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13,x10, x11, x12);
return test;
}

// Spliting the two digit numbers and getting their sum
int splittwo_sum(int x)
{

    if(x > 9 )
    {
        int sum_split = x % 10;
        int sum_split1 = (x - sum_split) / 10 + sum_split;
        return sum_split1;
    }
    else{
        return x;
    }
}

//Create function to check Luhn’s Algorithm result for 15 digit credit card
int fiftenlng(long x)
{

a1 = x % 10;
x2 = x % 100;
x3 = x % 1000;
x4 = x % 10000;
x5 = x % 100000;
x6 = x % 1000000;
x7 = x % 10000000;
x8 = x % 100000000;
x9 = x % 1000000000;
x10 = x % 10000000000;
x11 = x % 100000000000;
x12 = x % 1000000000000;
x13 = x % 10000000000000;
x14 = x % 100000000000000;

a2 = (x2 - a1) / 10;
a3 = (x3 - x2) / 100;
a4 = (x4 - x3) / 1000;
a5 = (x5 - x4) / 10000;
a6 = (x6 - x5) / 100000;
a7 = (x7 - x6) / 1000000;
a8 = (x8 - x7) / 10000000;
a9 = (x9 - x8) / 100000000;
a10 = (x10 - x9) / 1000000000;
a11 = (x11 - x10) / 10000000000;
a12 = (x12 - x11) / 100000000000;
a13 = (x13 - x12) / 1000000000000;
a14 = (x14 - x13) / 10000000000000;
a15 = (x - x14) / 100000000000000;

int sum1 = splittwo_sum(a14*2) + splittwo_sum(a12*2) + splittwo_sum(a10*2) + splittwo_sum(a8*2) + splittwo_sum(a6*2) + splittwo_sum(a4*2) + splittwo_sum(a2*2);
int sum2 = a15 + a13 + a11 + a9 + a7 + a5 + a3 +a1;
int sum_tot = sum1 + sum2;
int test = sum_tot%10;
//printf("tottal sum : %d %d %d\n",sum_tot, sum2, sum1);
//printf("all num : %d %d %d %d %d %d %d %d %d %d %d %d %d %ld %ld %ld\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13,x10, x11, x12);
return test;
}


//Create function to check Luhn’s Algorithm result for 16 number credit card
int sixtenlng(long x)
{

a1 =x % 10;
x2 = x % 100;
x3 = x % 1000;
x4 = x % 10000;
x5 = x % 100000;
x6 = x % 1000000;
x7 = x % 10000000;
x8 = x % 100000000;
x9 = x % 1000000000;
x10 = x % 10000000000;
x11 = x % 100000000000;
x12 = x % 1000000000000;
x13 = x % 10000000000000;
x14 = x % 100000000000000;
x15 = x % 1000000000000000;

a2 = (x2 - a1) / 10;
a3 = (x3 - x2) / 100;
a4 = (x4 - x3) / 1000;
a5 = (x5 - x4) / 10000;
a6 = (x6 - x5)/ 100000;
a7 =(x7 - x6) / 1000000;
a8 = (x8 - x7) / 10000000;
a9 = (x9 - x8) / 100000000;
a10 =(x10 - x9) / 1000000000;
a11 =(x11 - x10) / 10000000000;
a12 =(x12 - x11) / 100000000000;
a13 =(x13 - x12) / 1000000000000;
a14 =(x14 - x13) / 10000000000000;
a15 =(x15 - x14) / 100000000000000;
a16 =(x - x14) / 1000000000000000;

int sum1 = splittwo_sum(a16*2) + splittwo_sum(a14*2) + splittwo_sum(a12*2) + splittwo_sum(a10*2) + splittwo_sum(a8*2) + splittwo_sum(a6*2) + splittwo_sum(a4*2) + splittwo_sum(a2*2);
int sum2 = a15 + a13 + a11 + a9 + a7 + a5 + a3 +a1;
int sum_tot = sum1 + sum2;
int test = sum_tot%10;
//printf("tottal sum : %d %d %d\n",sum_tot, sum2, sum1);
//printf("all num : %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d  %ld %ld %ld\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, x10, x11, x12);
return test;
}