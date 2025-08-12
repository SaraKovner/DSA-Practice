/*
 * Description: Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 *  
 * Example 1:
 * Input:
 * matrix = [
 *   ["1", "0", "1", "0", "0"],
 *   ["1", "0", "1", "1", "1"],
 *   ["1", "1", "1", "1", "1"],
 *   ["1", "0", "0", "1", "0"]
 * ]
 * Output: 4
 * Explanation: The largest square has side length 2, so the area is 2 * 2 = 4.
 *  
 * Example 2:
 * Input:
 * matrix = [
 *   ["0", "1"],
 *   ["1", "0"]
 * ]
 * Output: 1
 *  
 * Example 3:
 * Input:
 * matrix = [
 *   ["0"]
 * ]
 * Output: 0
 *  
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה מטריצה בינארית, מצא את הריבוע הגדול ביותר המכיל רק 1ים והחזר את שטחו
 * 
 * Time Complexity: O(m*n) - תכנות דינמי
 * Space Complexity: O(m*n) - מטריצת DP
 */
#include "Question.h"
#define MIN(a, b) ((a)<(b)? (a) : (b))
#define MAX(a, b) ((a)>(b)? (a) : (b))
// פונקציה ראשית למציאת שטח הריבוע הגדול ביותר במטריצה בינארית
// אלגוריתם: תכנות דינמי - dp[i][j] = גודל הריבוע הגדול ביותר שקודקודו הימני-תחתון ב-(i,j)
int  find_square(ARR  *  matrix)  
{
    int n=matrix->dimensions[0]; // מספר שורות
    int m=matrix->dimensions[1]; // מספר עמודות
    
    // יצירת מטריצת DP בגודל (n+1)x(m+1) לטיפול נוח בגבולות
    int** dp=(int**)malloc((n+1)*sizeof(int*));
    for(int i=0; i<=n; i++)
        dp[i]=(int*)calloc(m+1, sizeof(int)); // אתחול ל-0
        
    int max_size=0; // גודל הצלע המקסימלי
    
    // מעבר על כל תא במטריצה המקורית
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            // אם התא הנוכחי הוא 1
            if(matrix->data[i*n+j]==1)
            {
                // נוסחת DP: מינימום של שלושת השכנים (למעלה, שמאלה, אלכסון) + 1
                dp[i+1][j+1]=MIN(dp[i][j], MIN(dp[i][j+1], dp[i+1][j]))+1;
                
                // עדכון המקסימום
                max_size=MAX(max_size, dp[i+1][j+1]);
            }
    
    // שחרור זיכרון
    for(int i=0; i<=n; i++)
        free(dp[i]);
    free(dp);
    
    return max_size*max_size; // החזרת השטח (צלע^2)
}