/*
 * Problem Description:
 * The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
 * Given an integer n, return the number of distinct solutions to the n-queens puzzle.
 * 
 * Example 1:
 *     Input: n = 4
 *     Output: 2
 * 
 * Example 2:
 *     Input: n = 1
 *     Output: 1
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: בעיית N מלכות - ספירת מספר הפתרונות להצבת N מלכות על לוח שחמט כך שלא תתקפנה אחת את השנייה
 * 
 * Time Complexity: O(N!) - במקרה הרע בודקים כל הצבות אפשריות
 * Space Complexity: O(n) - עומק הרקורסיה ומערכי המעקב
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <vector>

// פונקציה רקורסיבית לחיפוש כל הפתרונות האפשריים
// אלגוריתם Backtracking עם מעקב אחר עמודות ואלכסונים
int rec(vector<int>& order, int index, int n, 
        vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2)
{
    // מקרה בסיס: אם הצבנו כל מלכה בשורה שלה - מצאנו פתרון
    if(index == n)
        return 1;
      
    int count = 0; // מונה הפתרונות מהמצב הנוכחי
    
    // ניסיון להציב מלכה בכל עמודה בשורה הנוכחית
    for(int i = 0; i < n; i++)
    {
        // חישוב אינדקסי האלכסונים (עם הסטה למניעת אינדקס שלילי)
        int d1 = index - i + n;   // אלכסון ראשי (משמאל עליון לימין תחתון)
        int d2 = index + i;       // אלכסון משני (מימין עליון לשמאל תחתון)
        
        // בדיקה אם המיקום חופשי: לא תוקפת עמודה או אלכסונים
        if (!cols[i] && !diag1[d1] && !diag2[d2])
        {
            // סימון המיקום כתפוס (עמודה ואלכסונים)
            cols[i] = diag1[d1] = diag2[d2] = true;
            order.push_back(i); // הוספת המלכה לפתרון הנוכחי

            // קריאה רקורסיבית לשורה הבאה
            count += rec(order, index + 1, n, cols, diag1, diag2);
            
            // Backtrack: ביטול השינויים לפני המשך הלולאה
            cols[i] = diag1[d1] = diag2[d2] = false;
            order.pop_back();
        }
    }
    
    return count; // החזרת מספר הפתרונות מהמצב הנוכחי
}

// פונקציה ראשית לפתרון בעיית N מלכות
// אלגוריתם: Backtracking עם מעקב אחר התקפות בעמודות ואלכסונים
int n_queens(int n) 
{
    vector<int> order;           // סדר הצבת המלכות (עמודה לכל שורה)
    vector<bool> cols(n, false); // מעקב עמודות תפוסות
    vector<bool> diag1(2*n, false); // מעקב אלכסונים ראשיים
    vector<bool> diag2(2*n, false); // מעקב אלכסונים משניים

    return rec(order, 0, n, cols, diag1, diag2); // התחלת החיפוש הרקורסיבי
}
