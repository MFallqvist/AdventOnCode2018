#include <stdio.h>

#define MAXCHAR 1000

int main()
{
    FILE *fptr;
    int input=0, result=0;
    char* filename = "C:\\Users\\essiq\\github\\inlearning\\C\\advent_on_code\\day1.txt";

    fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }
    while ( fscanf(fptr, "%d", &input) != EOF) //(input = getw(fptr)) != EOF)
    {
        result += input;
        printf("%4d \n", input);
    }

    fclose(fptr);

    printf("The final result is: %d and final number %d \n", result, input);

    return 0;
}
