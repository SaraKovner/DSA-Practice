/*
 * Problem: You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
 * The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
 * An obstacle and space are marked as 1 or 0 respectively in the grid. A path that the robot takes cannot include any square that is an obstacle.
 * Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
 * 
 * Example 1:
 * Input: grid = [[0,0,0],[0,1,0],[0,0,0]]
 * Output: 2
 * Explanation: There are 2 unique paths from grid[0][0] to grid[2][2] that do not pass through any obstacles.
 * 
 * Example 2:
 * Input: grid = [[0,1],[0,0]]
 * Output: 1
 * Explanation: There is 1 unique path from grid[0][0] to grid[1][1] that does not pass through any obstacles.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך דו-ממדי עם מכשולים, מצא מספר המסלולים הייחודיים מפינה שמאלית עליונה לפינה ימנית תחתונה
 * 
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה ראשית לחישוב מספר המסלולים הייחודיים ברשת עם מכשולים
// אלגוריתם: Dynamic Programming - בניית טבלה לשמירת מספר המסלולים לכל תא
int count_unique_paths(ARR<ARR<int>> grid) 
{
    if(grid[0][0]==1)
        return 0;   // אם יש מכשול בנקודת המוצא - אי אפשר לצאת
    
    int n=grid.elements.size(); // מספר השורות
    int m=grid.elements[0].elements.size(); // מספר העמודות
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // טבלת DP מאותחלת לאפסים
    
    dp[1][1]=1; // נקודת המוצא - יש מסלול אחד להגיע אליה
    
    // מעבר על כל התאים ברשת
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            // אם זה לא נקודת המוצא ואין מכשול בתא הנוכחי
            if((i!=1 || j!=1) && grid[i-1][j-1]!=1)
                // מספר המסלולים = סכום המסלולים מלמעלה ומשמאל
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        
    return dp[n][m]; // החזרת מספר המסלולים ליעד
}