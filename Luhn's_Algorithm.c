//Checks to see if a card has a valid number using Luhn's algorithm and the nclassifying into one of three card categories(Visa, Amex, Mastercard)
//Libraries
#include <cs50.h>
#include <math.h>
#include <stdio.h>

//Prototypes
int length(long x);
int sum(long y, int z);
int sum2(long f, int g);
void check(long s, int q, int o);

//Main function
int main(void)
{
    long n = get_long("Enter Card Number: ");
    int len = length(n);
    int first = sum(n, len);
    int second = sum2(n, len);
    int summation = first + second;
    check(n, len, summation);
}

//Checks type of card
void check(long s, int q, int o)
{
    if (o % 10 == 0)
    {
        long r = pow(10, q);
        long t = pow(10, q - 2);
        int u = (s % r) / t;
        if ((q == 13 || q == 16) && (u >= 40 && u <= 49))
        {
            printf("VISA\n");
        }
        else if ((u == 34 || u == 37) && q == 15)
        {
            printf("AMEX\n");
        }
        else if ((u >= 51 && u <= 55) && q == 16)
        {
            printf("MASTERCARD\n");
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

//Sums all the remaining digits
int sum2(long f, int g)
{
    int h = 0;
    for (int j = 1; j < g + 1; j += 2)
    {
        long k = pow(10, j);
        long m = pow(10, j - 1);
        int l = (f % k) / m;
        h = h + l;
    }
    return h;
}

//Starting with the second to last number and skipping every other number, this multiplies that digit by two and sums the digits (not the whole number)
int sum(long y, int z)
{
    int b = 0;
    for (int i = 2; i < z + 2; i += 2)
    {
        long d = pow(10, i);
        long e = pow(10, i - 1);
        int a = (y % d) / e;
        a = a * 2;
        if (a < 10)
        {
            b = b + a;
        }
        else
        {
            int c = a % 10;
            b += c + 1;
        }
    }
    return b;
}

//Determine length of card number
int length(long x)
{
    int counter = 0;
    long copy = x;

    while (copy != 0)
    {
        copy = copy / 10;
        counter++;
    }
    return counter;
}
