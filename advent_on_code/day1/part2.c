#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define MAXCHAR 1000
#define MAXF 500000

int seen[MAXF] = {0};

bool duplicate(int compare, int n)
{
    int c;

    //printf("duplicate of : %d, %d\n",seen[0], compare);
    for (c = 0; c < n; c++)
    {
        //printf("Comparing %d items: %d == %d\n", n, compare, seen[c]);

        if(seen[c] == compare)
        {
            printf("Done duplicate of number: %d\n",seen[c]);
            return true;
        }
    }
    return false;
}

// Calculate and save frequencies, output first frequency to be reached twice
int main()
{
    FILE *fptr;
    int current = 0, result = 0, index = 1;
    char* filename = "C:\\Users\\essiq\\github\\inlearning\\C\\advent_on_code\\day1.txt";

    puts("Opening to read file");
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }

    while ( 1 )
    {
        if(fscanf(fptr, "%d", &current) == EOF)
        {
            fptr = fopen(filename, "r");
            continue;
        }

        result += current;
        // Add this frequency
        if(duplicate(result, index)) // If true we reached a repeated frequency
        {
            printf("Breaking with final answer: %d \n", result); // Goal reached, 2nd time we reach this resulting freq
            break;
        }
        else
        {
            seen[index] = result;
            index++;
        }
    }

    fclose(fptr);

    printf("End of script\n");

    return 0;
}
