/*
 * Problem: Given an m x n grid filled with non-negative numbers, find a path from the top-left corner to the bottom-right corner that minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה רשת m x n ממולאת במספרים לא-שליליים, מצא נתיב מהפינה השמאלית העליונה לפינה הימנית התחתונה שממעט את סכום כל המספרים בנתיב
 * 
 * Example:
 * Input:
 * grid = [
 *   [1,3,1],
 *   [1,5,1],
 *   [4,2,1]
 * ]
 * Output: 7
 * 
 * Explanation:
 * For the input [[1,3,1],[1,5,1],[4,2,1]], the path [1,3,1,1,1] minimizes the sum, resulting in 7.
 * 
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n) - לטבלת DP
 */
//#define ARR_DATA_TYPE int
#include "Question.h"
#include <limits.h>

// פונקציית עזר למציאת מינימום בין שני מספרים
int min(int a, int b)
{
    return a>b ? b : a;
}

// int rec(ARR* grid, int i, int j)
// {
//     int row=grid->dimensions[0];
//     int col=grid->dimensions[1];
//     if(i>=row || j>=col)
//         return INT_MAX; //אין סוף
   
    
//     uint64_t indexs[2]={i, j};
//     int num= grid->data[ARR_CalculateIndex(grid, indexs)];
    
//     //אם הגענו למיקום האחרון
//     if(i==row-1 && j==col-1)
//         return num;
        
//     return num + min(rec(grid, i+1, j), rec(grid, i, j+1));
// }

// פונקציה ראשית למציאת סכום מינימלי בנתיב ברשת
int  min_grid_sum(ARR  *  grid) 
{
    // פתרון דינמי - בניית טבלת DP מהסוף להתחלה
    int row=grid->dimensions[0]; // מספר שורות
    int col=grid->dimensions[1]; // מספר עמודות
    int i, j;
    
    int **dp=(int**)malloc(row*sizeof(int*));    //הקצאת השורות
    for(j=0; j<row; j++)
        dp[j]=(int*)malloc(col*sizeof(int));    //הקצאת העמודות
    
    //אתחול מקרה הבסיס
    uint64_t index[2]={row-1, col-1};
    dp[row-1][col-1]=grid->data[ARR_CalculateIndex(grid, index)];
    
    //index[0]=row-1;
    //אתחול השורה האחרונה והעמודה האחרונה
    for(j=col-2; j>=0; j--)
    {
        index[1]=j;
        dp[row-1][j]=grid->data[ARR_CalculateIndex(grid, index)]+dp[row-1][j+1];
    }
    index[1]=col-1;
    for(i=row-2; i>=0; i--)
    {
        index[0]=i;
        dp[i][col-1]=grid->data[ARR_CalculateIndex(grid, index)]+dp[i+1][col-1];
    }
    
    //החישוב עצמו
    for(i=row-2; i>=0; i--)
        for(j=col-2; j>=0; j--)
        {
            index[0]=i;
            index[1]=j;
            int curr=grid->data[ARR_CalculateIndex(grid, index)];
            dp[i][j]=curr+min(dp[i+1][j], dp[i][j+1]);
        }
    
    
    int ans=dp[0][0];
    
    //שחרור
    for(j=0; j<row; j++)
        free(dp[j]);
    free(dp);
    
    return ans;
    // return rec(grid, 0, 0);  
}
