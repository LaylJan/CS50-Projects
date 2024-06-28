#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    while (true)
    {
        height = get_int("Height: ");
        if (height < 9 && height > 0)
            break;
    }
    for (int i = 1; i < height + 1; i++)
    {
        for (int j = height; !(j == i); j--)
        {
            printf(" ");
        }
        for (int k = 8 - i; k != 8; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int k = 8 - i; k != 8; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}