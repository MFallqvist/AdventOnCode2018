// Marcus F 20190507
// Calculate checksum from text file
#include <stdio.h>
#include <string.h>

int * duplicate(char original[], int * result)
{
    int n = strlen(original), c, i, counter, dup=0,trip=0;
    int checksum[32][2] = {0};
    char candidate;

    //printf("duplicate called with string %s and result %d,%d: \n",original,result[0],result[1]);
    for (c = 0; c < n; c++) // Looping over this string one candidate at the time
    {
        counter = 0;
        candidate = original[c];
        for (i = 0; i < n; i++) // Looping with selected candidate over array
        {
            //printf("Comparing item %d: %c == %c\n", c, original[i], candidate);
            if(original[i] == candidate)
            {
                counter++; // Increment if the candidate is found
            }
        }
        if(counter == 2) // A duplicate, set correct element of checksum
        {
            checksum[c][0] = 1;
            //printf("Duplicate of char: %c\n",candidate);
        }
        if(counter == 3)
        {
            checksum[c][1] = 1;
            //printf("Triple of char: %c\n",candidate);
        }

    }
    // control checksum matrix and return correct value
    for (c = 0; c < n; c++) // Looping over this string one candidate at the time
    {
        if(checksum[c][0] == 1)
        {
            dup = 1;
           // printf("A duplicate is found: %d \n",result[0]);
        }

        if(checksum[c][1] == 1)
        {
            trip = 1;
            //printf("A Triple is found: %d \n",result[1]);
        }

    }
    result[0] += dup;
    result[1] += trip;
    //printf("Returning: %d and %d\n",result[0], result[1]);
    return result;
}

// Calculate and save frequencies, output first frequency to be reached twice
int main()
{
    FILE *fptr;
    char* filename = "C:\\Users\\essiq\\github\\inlearning\\C\\advent_on_code\\day2\\input.txt";
    int *iptr;
    int result[2] = {0}, index = 1;
    char current[32];

    puts("Running script day2");
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }

    while ( fscanf(fptr, "%s", &current) != EOF )
    {
        iptr = duplicate(current, result);
        //printf("Current numbers: %d and %d \n", *(iptr), *(iptr+1));
        //result[0] += *(iptr);
        //result[1] += *(iptr+1);

    }

    fclose(fptr);

    printf("End of script with result: %d \n", result[0]*result[1]);

    return 0;
}
