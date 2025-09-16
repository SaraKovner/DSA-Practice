/*
 * Description:
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
 * An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are surrounded by water.
 * 
 * Example 1:
 * Input:
 * grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * Example 2:
 * Input:
 * grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * Constraints:
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: ספירת מספר האיים ברשת בינארית דו-ממדית
 * 
 * Time Complexity: O(m*n) - במקרה הגרוע עוברים על כל התאים
 * Space Complexity: O(m*n) - עומק הרקורסיה במקרה הגרוע
 */
#include "Question.h"

// פונקציית עזר DFS לסימון כל האי הנוכחי
// אלגוריתם: Depth-First Search - חיפוש לעומק לסימון תאים מחוברים
void dfs(ARR* grid, int row, int col)
{
    // בדיקת גבולות ותנאי עצירה
    if(row < 0 || col < 0 || 
       row >= grid->dimensions[0] || col >= grid->dimensions[1] || 
       grid->data[row * grid->dimensions[1] + col] == 0)
       return;
       
    // סימון התא הנוכחי כ"ביקר" (הפיכה ל-0)
    grid->data[row * grid->dimensions[1] + col] = 0;
    
    // רקורסיה על כל 4 הכיוונים הסמוכים
    dfs(grid, row + 1, col);    // למטה
    dfs(grid, row - 1, col);    // למעלה
    dfs(grid, row, col - 1);    // שמאלה
    dfs(grid, row, col + 1);    // ימינה
}

// פונקציית עזר לספירת איים
int num_Islands(ARR* grid)
{
    int count = 0; // מונה האיים
    int n = grid->dimensions[0]; // מספר השורות
    int m = grid->dimensions[1]; // מספר העמודות
    
    // מעבר על כל התאים ברשת
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(grid->data[i * m + j] == 1) // אם מצאנו יבשה שלא ביקרנו
            {
                dfs(grid, i, j); // סימון כל האי באמצעות DFS
                count++; // הגדלת מונה האיים
            }
    return count;
}

// פונקציה ראשית לספירת מספר האיים ברשת בינארית
// אלגוריתם: DFS (Depth-First Search) - חיפוש לעומק לזיהוי רכיבים מחוברים
int count_islands(ARR* grid) 
{
    // יצירת עותק של הרשת כדי לא לשנות את המקור
    uint64_t d[2] = {grid->dimensions[0], grid->dimensions[1]};
    ARR* newGrid = ARR_Create(d, 2);
    
    // העתקת הנתונים לרשת החדשה
    for(int i = 0; i < grid->total_size; i++)
        newGrid->data[i] = grid->data[i];
    
    // ספירת האיים ברשת המועתקת
    int count = num_Islands(newGrid);
    
    // שחרור זיכרון הרשת הזמנית
    ARR_Free(newGrid);
    return count;
}