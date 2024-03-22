//Program to generate pyramids out of #'s similar to what is seen in Mario world
//Libraries
#include <cs50.h>
#include <stdio.h>

//Main Function
int main(void)
{
    int num;
    // prompt user for positive integer
    //Input Size Desired
    do
    {
        num = get_int("Size: ");
    }
    //Determine desired size and print appropriately
    while (num < 1);
    num += 1;
    int m = num - 1;
    for (int i = 1; i < num; i++)
    {
        for (int j = 1; j < m; j++)
        {
            printf(" ");
        }
        m -= 1;
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
