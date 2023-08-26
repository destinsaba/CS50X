#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // Get input
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    // card length
    long n = card;
    int length = 0;
    while (n > 0)
    {
        n = n / 10;
        length++;
    }

    // Calc checksum (Luhn's Algorithm)
    // 1. Multiply every other digit by 2, starting with the second number to the last
    // 2. Add the sum of those digits
    // 3. Add the sum of the other digits
    // 4. If the total sum ends with a 0, it is valid

    long sumlast = 0;
    long sumsec = 0;
    long dig = 0;

    // Sum of the other digits
    for (int i = 0; i < length; i = i + 2)
    {
        // Factor of ten to truncate end digits
        long ten = pow(10, i);

        // Sum of other digits
        sumlast = sumlast + (card / ten) % 10;
    }

    // Sum other digits multiplied by 2
    for (int i = 1; i < length; i = i + 2)
    {
        // Factor of ten to truncate end digits
        long ten = pow(10, i);

        // Sum of other digits multiplied by 2
        dig = (card / ten) % 10 * 2;
        if (dig > 9)
        {
            int first = dig / 10;
            int second = dig % 10;
            dig = first + second;
        }
        sumsec = sumsec + dig;
    }

    // Check total sum
    long remainder = (sumsec + sumlast) % 10;

    // Get starting digits
    long first2 = (card / pow(10, (length - 2)));

    // Print card type or invalid
    if (remainder != 0)
    {
        printf("INVALID\n");
    }
    else if ((length == 16) && (first2 == 51 || first2 == 52 || first2 == 53 || first2 == 54 || first2 == 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 15) && (first2 == 34 || first2 == 37))
    {
        printf("AMEX\n");
    }
    else if ((length == 13 || length == 16) && (first2 / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}