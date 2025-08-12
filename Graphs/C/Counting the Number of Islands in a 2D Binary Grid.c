//#define ARR_DATA_TYPE int
#include "Question.h"

void dfs(ARR* grid, int row, int col)
{
    if(row<0 || col<0 || 
       row>=grid->dimensions[0] || col>=grid->dimensions[1] || 
       grid->data[row*grid->dimensions[1]+col]==0)
       return;
       
    grid->data[row*grid->dimensions[1]+col]=0;
    dfs(grid, row+1, col);    //מתחתי
    dfs(grid, row-1, col);    //מעלי
    dfs(grid, row, col-1);    //משלמאל
    dfs(grid, row, col+1);    //מימין
}

int num_Islands(ARR* grid)
{
    int count=0;
    int n=grid->dimensions[0];
    int m=grid->dimensions[1];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid->data[i*m+j]==1)
            {
                dfs(grid, i, j);
                count++;
            }
    return count;
}

int  count_islands(ARR*  grid) 
{
    uint64_t d[2]={grid->dimensions[0], grid->dimensions[1]};
    ARR* newGrid=ARR_Create(d, 2);
    for(int i=0; i<grid->total_size; i++)
        newGrid->data[i]=grid->data[i];
    
    int count=num_Islands(newGrid);
    
    ARR_Free(newGrid);
    return count;  
}
