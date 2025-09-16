/*
 * Given an m x n integer matrix, return the length of the longest increasing path in the matrix.
 * From each cell, you can move in four directions: left, right, up, or down.
 * You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
 * 
 * Example:
 * Given matrix = [[9,9,4],[6,6,8],[2,1,1]], the longest increasing path is 4 (i.e., 1 -> 2 -> 6 -> 9).
 * 
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 200
 * 0 <= matrix[i][j] <= 2^31 - 1
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מציאת הנתיב הגדל הארוך ביותר במטריצה
 * 
 * Time Complexity: O(m*n*log(m*n)) - מיון כל התאים + DP
 * Space Complexity: O(m*n) - טבלת DP ו-Priority Queue
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <utility>
#include <queue>
using namespace std;

// פונקציה ראשית למציאת הנתיב הגדל הארוך ביותר במטריצה
// אלגוריתם: Topological Sort + Dynamic Programming עם Priority Queue
int increas_path(ARR<ARR<int>> matrix) 
{
    int maxLength = 0;
    int n = matrix.elements.size();    // מספר שורות
    int m = matrix[0].elements.size(); // מספר עמודות
    
    // Priority Queue למיון התאים לפי ערך (מהגדול לקטן)
    priority_queue<pair<int, pair<int, int>>> pq;
    
    // טבלת DP: dp[i][j] = אורך הנתיב הארוך ביותר המתחיל מ-(i,j)
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // כיוונים אפשריים: למעלה, שמאלה, ימינה, למטה
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    
    // הוספת כל התאים ל-Priority Queue
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            pq.push({matrix[i][j], {i, j}});
    
    // עיבוד התאים מהגדול לקטן (Topological Sort)
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int row = top.second.first, col = top.second.second;
        
        // בדיקת כל השכנים
        for(auto [dr, dc] : directions)
        {
            int nr = row + dr; // שורה חדשה
            int nc = col + dc; // עמודה חדשה
            
            // בדיקת גבולות ותנאי גידול
            if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
               matrix[row][col] < matrix[nr][nc])
            {
                // עדכון DP: הנתיב הארוך ביותר דרך השכן
                dp[row][col] = max(dp[row][col], dp[nr][nc]);
            }
        }
        
        dp[row][col]++; // הוספת התא הנוכחי לנתיב
        maxLength = max(maxLength, dp[row][col]); // עדכון המקסימום
    }
    
    return maxLength;  
}