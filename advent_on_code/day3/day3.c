// Day 3 Marcus F 20190508

#include <stdio.h>
#include <string.h>
#define N 1024
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

static int grid[N][N];
static int free_tiles[2*N] = {0};

void d3_FillGrid(int index, int topleft, int top, int width, int height)
{
    int row, col, conflict = 0;

    for(row = topleft; (row < width+topleft) && (row < N); row++)
    {
        for(col = top; col < (height+top) && (col < N); col++)
        {
            if(grid[row][col] > 0 || grid[row][col] == -1)
            {
                free_tiles[grid[row][col]] = 0;
                free_tiles[index] = 0;
                conflict = 1;
                grid[row][col] = -1;
            }

            else
            {
                //free_tiles[grid[row][col]] = 1;
                if(!conflict)
                    free_tiles[index] = 1;
                grid[row][col] = index;
            }

        }
    }

}
int d3_EvaluateOverlap()
{
    int row, col, result=0;
    //printf("compare: %s and %s \n",original, compare);
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < N; col++)
        {
            if(grid[row][col] == -1)
                result++;
        }
    }
    return result;
}
int d3_EvaluateFree()
{
    int id, result=0;
    //printf("Size of free_tiles: %d \n",NELEMS(free_tiles));
    for(id = 0; id < NELEMS(free_tiles); id++)
    {
        if(free_tiles[id] == 1)
            result=id;

    }
    return result;
}


void d3_ShowGrid()
{
    int row, col, result=0;
    printf("Grid: \n");
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < N; col++)
        {
            printf("%2d", grid[row][col]);
        }
        printf("\n");
    }
}

// Calculate and save frequencies, output first frequency to be reached twice
int main()
{
    FILE *fptr;
    char* filename = "C:\\Users\\essiq\\github\\inlearning\\C\\advent_on_code\\day3\\input.txt";
    int index = 0, result = 0, free_id = 0, topleft, top, width, height;


    puts("Running day 3 ");
    fptr = fopen(filename, "r");


    if (fptr == NULL){
        printf("Could not open file %s", filename);
        return 1;
    }
    // Loop for each word
    while ( fscanf(fptr, "#%d @ %d,%d: %d x%d\n", &index, &topleft, &top, &width, &height) != EOF )
    {
        printf("Read #%d @ %d,%d: %d x %d\n", index, topleft, top, width, height);
        d3_FillGrid(index, topleft, top, width, height);
    }
    result = d3_EvaluateOverlap();
    free_id = d3_EvaluateFree();
    fclose(fptr);

    //d3_ShowGrid();
    printf("End of script with result: %d \n", result);
    printf("Free tile patch with id: %d \n", free_id);

    return 0;
}

