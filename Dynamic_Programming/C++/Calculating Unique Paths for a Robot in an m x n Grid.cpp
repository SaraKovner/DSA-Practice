/*
 * Problem: There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
 * The robot can only move either down or right at any point in time.
 * Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
 * The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
 * 
 * Example:
 * Input: m = 3, n = 7
 * Output: 28
 * 
 * Input: m = 3, n = 2
 * Output: 3
 * 
 * Explanation:
 * For the input m = 3, n = 7, the number of unique paths from grid[0][0] to grid[2][6] is 28.
 * For the input m = 3, n = 2, the number of unique paths from grid[0][0] to grid[2][1] is 3.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון רובוט ברשת m x n, מצא מספר המסלולים הייחודיים מפינה שמאלית עליונה לפינה ימנית תחתונה
 * 
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה ראשית לחישוב מספר המסלולים הייחודיים ברשת m x n
// אלגוריתם: Dynamic Programming - בניית טבלה לשמירת מספר המסלולים לכל תא
int calculate_paths(int m, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // טבלת DP מאותחלת לאפסים
    
    dp[1][1]=1; // נקודת המוצא - יש מסלול אחד להגיע אליה
    
    // מעבר על כל התאים ברשת
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if((i!=1 || j!=1)) // אם זה לא נקודת המוצא
                // מספר המסלולים = סכום המסלולים מלמעלה ומשמאל
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
    
    return dp[n][m]; // החזרת מספר המסלולים ליעד
}