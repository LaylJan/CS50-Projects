#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int name = get_int("What's your name? ");
    printf("hello, %\n", name);
}