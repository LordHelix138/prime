#include <cs50.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, string argv[])
{
    clock_t start_time, end_time;
    start_time = clock();
    FILE *pF = fopen("primes.txt", "a+");

    char buffer[255];
    char *endptr;
    string last;

    if (argc < 2)
    {
        printf("Usage: count [number] returns all primes up to and including the input number\n");
        return 1;
    }

    unsigned long long MAX = strtoull(argv[1], &endptr, 10);


    bool *not_prime = calloc(MAX + 1, sizeof(bool));
    if (not_prime == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    not_prime[0] = true;
    not_prime[1] = true;

    if (fgets(buffer, 255, pF) == NULL)
    {
        last = "2";
    }
    else while(fgets(buffer, 255, pF) != NULL)
    {
        last = buffer;
    }

    //printf("%lli\n", atoll(last)); debug line for finding last number in already made list (if I want to be able to terminate and pick back up)



    for(unsigned long long i = 2; i <= MAX; i++)
    {
        //fprintf(pF, "%llu is not prime? %lli\n", i, (long long)not_prime[i]);
        if (not_prime[i] == false)
        {
            fprintf(pF, "%llu\n", i);
            for(unsigned long long j = 2; j < (MAX / i) + 1; j++)
            {
                //fprintf(pF, "i = %llu - j = %llu - i * j = %llu\n", i, j, i * j); //debug line to see multiples of primes that are removed
                if (j * i <= MAX)
                {
                    not_prime[j * i] = true;
                }
                else
                {
                    continue;
                }
            }
        }
    }



    //fprintf(pF, "%s", argv[1]);

    fclose(pF);
    free(not_prime);
    end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;
    printf("Execution time: %.2f milliseconds\n", elapsed_time);
    return 0;
}
