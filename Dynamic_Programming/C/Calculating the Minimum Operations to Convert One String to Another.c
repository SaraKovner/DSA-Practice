/*
 * Problem: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
 * You have the following three operations permitted on a word:
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: נתונות שתי מחרוזות word1 ו-word2, החזר את מספר הפעולות המינימלי להמרת word1 ל-word2
 * 
 * Example:
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * 
 * Explanation:
 * For the input "horse", "ros", the minimum number of operations to convert "horse" to "ros" is 3 (delete 'h', replace 'r' with 'o', delete 'e').
 * For the input "intention", "execution", the minimum number of operations to convert "intention" to "execution" is 5 (replace 'i' with 'e', replace 'n' with 'x', replace 't' with 'c', insert 'u', insert 'n').
 * 
 * Time Complexity: O(n*m)
 * Space Complexity: O(n*m)
 */
#include "Question.h"
#include <string.h>
#include <stdlib.h>

// פונקציית עזר למציאת מינימום של 3 מספרים
int min_(int a, int b, int c)
{
    int m = a > b ? b : a;
    return m < c ? m : c;
}

// פונקציה יעילה לחישוב מרחק עריכה עם תכנות דינמי
// זמן: O(n*m), זיכרון: O(n*m)
int calculate_min_operations(STR word1, STR word2)  
{
    int n = strlen(word1.s);
    int m = strlen(word2.s);
    
    // יצירת טבלה דו-מימדית לתכנות דינמי
    int** dp = (int**)malloc((n+1) * sizeof(int*));
    for(int i = 0; i <= n; i++)
        dp[i] = (int*)malloc((m+1) * sizeof(int));
    
    // אתחול תנאי בסיס
    for(int i = 0; i <= n; i++)
        dp[i][0] = i; // מחיקת כל התווים מ-word1
    
    for(int j = 0; j <= m; j++)
        dp[0][j] = j; // הוספת כל התווים מ-word2
    
    // מילוי הטבלה
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(word1.s[i-1] == word2.s[j-1])
                dp[i][j] = dp[i-1][j-1]; // תווים זהים - אין פעולה
            else
                dp[i][j] = 1 + min_(
                    dp[i-1][j-1], // החלפה
                    dp[i][j-1],   // הוספה
                    dp[i-1][j]    // מחיקה
                );
        }
    }
    
    int result = dp[n][m];
    
    // שיחרור זיכרון
    for(int i = 0; i <= n; i++)
        free(dp[i]);
    free(dp);
    
    return result;
}