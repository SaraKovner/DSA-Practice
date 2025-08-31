/*
 * Problem: Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 *          1
 *         1 1
 *        1 2 1
 *       1 3 3 1
 *      1 4 6 4 1
 * 
 * Example 1:
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * Example 2:
 * Input: numRows = 1
 * Output: [[1]]
 * 
 * Difficulty: 🟢 Easy
 * 
 * תרגום: נתון מספר שורות, בנה את משולש פסקל עם המספר הנתון של שורות
 * 
 * Time Complexity: O(numRows²)
 * Space Complexity: O(numRows²)
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית לבניית משולש פסקל
// אלגוריתם: בניית כל שורה על בסיס השורה הקודמת - כל מספר הוא סכום שני המספרים מעליו
ARR<ARR<int>> pascal_triangle(int numRows)
{
    ARR<ARR<int>> res; // מערך התוצאות
    if(numRows==0)
        return res; // אם אין שורות - החזר מערך ריק
    
    // יצירת השורה הראשונה [1]
    ARR<int> row;
    row.elements.push_back(1);
    res.elements.push_back(row);

    // בניית השורות הנוספות
    for(int i=1; i<numRows; i++)
    {
        ARR<int> row; // שורה חדשה
        row.elements.push_back(1); // תמיד מתחילים ב-1
        
        // חישוב האלמנטים הפנימיים - סכום שני האלמנטים מהשורה הקודמת
        for(int j=1; j<i; j++)
            row.elements.push_back(res[i-1][j-1]+res[i-1][j]);
        
        row.elements.push_back(1); // תמיד מסיימים ב-1
        res.elements.push_back(row); // הוספת השורה למשולש
    }
    
    return res; // החזרת משולש פסקל המלא
}