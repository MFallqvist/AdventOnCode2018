// Day 4 Marcus F 20190509

#include <stdio.h>
#include <string.h>
#define N 1024
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

struct guard_struct{
    int id;
    int time_slept;
    int sleeping_minute;
    int awake; // 0 sleep, 1 awake
};

struct data{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    struct guard_struct guard;

};


// Calculate and save frequencies, output first frequency to be reached twice
int main()
{
    FILE *fptr;
    char* filename = "C:\\Users\\essiq\\github\\inlearning\\C\\advent_on_code\\day4\\testinput.txt";
    int id = 0, result = 0, free_id = 0, topleft, top, width, height;
    char text[4];
    //struct guard_struct temp;
    struct data temp;

    puts("Running day 4 ");
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }
    // Loop for each word
    while ( fscanf(fptr, "[%d-%d-%d %d:%d] %*s %s %*[^\n]",
                   &temp.year,
                   &temp.month,
                   &temp.day,
                   &temp.hour,
                   &temp.minute,
                   &text) != EOF )
    {
        printf("Read: [%d-%d-%d %d:%d] %s \n",
                temp.year,
                temp.month,
                temp.day,
                temp.hour,
                temp.minute,
                text
                );
        getchar();
        //d3_FillGrid(id, topleft, top, width, height);
    }
    //result = d3_EvaluateOverlap();
    //free_id = d3_EvaluateFree();
    fclose(fptr);

    //d3_ShowGrid();
    //printf("End of script with result: %d \n", result);
    //printf("Free tile patch with id: %d \n", free_id);

    return 0;
}

