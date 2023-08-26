#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while (size > 8 || size < 1);

    // print blocks
    int row = 0;
    for (int i = 0; i < size; i++)
    {
        row = row + 1;
        int spaces = size - row;

        // print leading spaces
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        // print left blocks
        for (int j = 0; j < row; j++)
        {
            printf("#");
        }

        // print constant space
        printf("  ");

        // print right blocks
        for (int j = 0; j < row; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}