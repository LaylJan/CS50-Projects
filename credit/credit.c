#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");
    long tmp = num;
    long odd = 0;
    long even = 0;
    int x;
    int count = 0;

    tmp = num;
    while (tmp > 0)
    {
        tmp /= 10;
        int digit = (tmp % 10) * 2;
        odd += (digit / 10) + (digit % 10);
        tmp /= 10;
    }

    tmp = num;
    even = tmp % 10;
    while (true)
    {
        tmp = tmp / 100;
        even = even + (tmp % 10);
        if (tmp <= 0)
            break;
    }

    if (!((odd + even) % 10 == 0))
    {
        printf("INVALID\n");
        return 0;
    }

    tmp = num;
    do
    {
        count++;
        tmp = tmp / 10;
    }
    while (!(tmp <= 0));

    if (count == 15) // AMERICAN EXPRESS
    {
        tmp = num;
        while (tmp >= 100)
        {
            tmp = tmp / 10;
        }
        if (tmp == 34 || tmp == 37)
        {
            printf("AMEX\n");
            return 0;
        }
    }
    if (count == 16) // MASTER CARD
    {
        tmp = num;
        while (tmp >= 100)
        {
            tmp = tmp / 10;
        }
        if (tmp == 51 || tmp == 52 || tmp == 53 || tmp == 54 || tmp == 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }
    if (count == 13 || count == 16) // VISA
    {
        tmp = num;
        do
        {
            tmp = tmp / 10;
        }
        while (tmp >= 10);

        if (tmp == 4)
        {
            printf("VISA\n");
            return 0;
        }
    }
    printf("INVALID\n");
    return 0;
}