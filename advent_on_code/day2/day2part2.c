// Marcus F 20190508 day2part2
// Check similarity between strings
#include <stdio.h>
#include <string.h>

int compare(char original[], char compare[])
{
    int n = strlen(original), c, same=0;
    //printf("compare: %s and %s \n",original, compare);
    for (c = 0; c < n; c++)
    {
        if(original[c] == compare[c])
        {
            same += 1;
            //result = compare;
            continue;
           // printf("A duplicate is found: %d \n",result[0]);
        }
    }
    if (same == n-1)
    {
        printf("Similarity found: %s - %s \n",original,compare);
        return 1;
    }
    else
        return 0;
}

// Calculate and save frequencies, output first frequency to be reached twice
int main()
{
    FILE *fptr, *reptr;
    char* filename = "C:\\Users\\essiq\\github\\inlearning\\C\\advent_on_code\\day2\\input.txt";
    int index = 0, counter = 0;
    char result[64], current[64], temp[64];

    puts("Running script day 2 part 2");
    fptr = fopen(filename, "r");


    if (fptr == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }
    // Loop for each word
    while ( fscanf(fptr, "%s", &current) != EOF )
    {
        counter = 0;
        reptr = fopen(filename, "r");
            // Compare it to all other words from this word forward
            while ( fscanf(reptr, "%s", &temp) != EOF )
            {
                if(counter > index)
                    if(compare(current, temp))
                    {
                        strcpy(result, temp);
                        strcat(result, " ");
                        strcat(result, current);
                        printf("Breaking with result: %s, %s \n", temp, current);
                        break;
                    }
                //printf("Current numbers: %d and %d \n", *(iptr), *(iptr+1));
                counter++;

            }
        index++;
    }

    fclose(fptr);

    printf("End of script with result: %s \n", result);

    return 0;
}

