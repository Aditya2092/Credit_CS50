#include <stdio.h>
#include <cs50.h>

// Function declaration
int splittwo_sum(int x);
int lenHelper(long x);
int thirtenlng(long x);

//int sum_tot;
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
    long num=get_long("enter a number: \n");
    //int Sumtotal=splittwo_sum(num*2);
    //printf("Sum of the number : %d \n",Sumtotal);

    int validtest=thirtenlng(num);
    printf("final number : %d \n",validtest);

}


int splittwo_sum(int x)
{

    if(x > 9 )
    {
        int sum_split=x%10;
        int sum_split1=(x-sum_split)/10 + sum_split;
        return sum_split1;
    }
    else{
        return x;
    }
}

int lenHelper(long x)
{
    if (x >= 1000000000000000 && x <= 9999999999999999 ) return 16;
    if (x >= 100000000000000 && x <= 999999999999999)  return 15;
    if (x >= 10000000000000 && x <= 99999999999999 )   return 14;
    if (x >= 1000000000000 && x <= 9999999999999 )    return 13;
    if (x >= 1000 && x <= 9999)    return 4;
    return 1;
}



int thirtenlng(long x)
{

a1=x%10;
x2=x%100;
x3=x%1000;
x4=x%10000;
x5=x%100000;
x6=x%1000000;
x7=x%10000000;
x8=x%100000000;
x9=x%1000000000;
x10=x%10000000000;
x11=x%100000000000;
x12=x%1000000000000;

a2=(x2-a1)/10;
a3=(x3-x2)/100;
a4=(x4-x3)/1000;
a5=(x5-x4)/10000;
a6=(x6-x5)/100000;
a7=(x7-x6)/1000000;
a8=(x8-x7)/10000000;
a9=(x9-x8)/100000000;
a10=(x10-x9)/1000000000;
a11=(x11-x10)/10000000000;
a12=(x12-x11)/100000000000;
a13=(x-x12)/1000000000000;

int sum1 = splittwo_sum(a12*2) + splittwo_sum(a10*2) + splittwo_sum(a8*2) + splittwo_sum(a6*2) + splittwo_sum(a4*2) + splittwo_sum(a2*2);
int sum2= a13 + a11 + a9 + a7 + a5 + a3 +a1;
int sum_tot= sum1 + sum2;
int test= sum_tot%10;
printf("tottal sum : %d %d %d\n",sum_tot, sum2, sum1);
printf("all num : %d %d %d %d %d %d %d %d %d %d %d %d %d %ld %ld %ld\n", a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13,x10, x11, x12);
return test;

}