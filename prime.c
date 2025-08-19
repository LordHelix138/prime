#include <cs50.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int prime;
    int exponent;
} factor;

bool isPrime(int i);

//unsigned long long int n;
unsigned int n;

#define ulprime 415828534307635077

int main(int argc, string argv[])
{
    // Check for invalid usage
    char *endptr;
    if (argc < 2)
    {
        printf("Usage: prime [Number to factorise]\nDecimals will be trucated and numbers larger than the ULLONG_MAX will be substituted with ULLONG_MAX\nAny non-numeric characters in input string will cause input to stop being read at the illegal character\nAn input starting with an illegal character will result in 0 being used\n");
        return 1;
    }
    if (strtoull(argv[1], &endptr, 10) == ULLONG_MAX)
    {
        printf("WARNING: Input >= ULLONG_MAX\n");
    }
    n = strtoul(argv[1], &endptr, 10);
    double root = sqrt(n);
    //printf("Num: %llu\nRoot: %lf\n", n, root);
    printf("Num: %u\nRoot: %lf\n", n, root);
    printf("%ld\n", ulprime);

    for (long int p = 2; p < ulprime;)
    {
        if (n % p == 0)
        {

        }
        else
        {
            p++;
        }
    }
}

bool isPrime(int i)
{

    return false;
}
