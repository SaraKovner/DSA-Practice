/*
 * Problem: Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
 * You may return the answer in any order.
 * 
 * Example:
 * Input: n = 4, k = 2
 * Output: [[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
 * 
 * Input: n = 3, k = 3
 * Output: [[1,2,3]]
 * 
 * Explanation:
 * For the input n = 4, k = 2, the possible combinations are [2,4], [3,4], [2,3], [1,2], [1,3], [1,4].
 * For the input n = 3, k = 3, the only possible combination is [1,2,3].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונים שני מספרים n ו-k, החזר את כל הקומבינציות האפשריות של k מספרים מהטווח [1, n]
 * 
 * Time Complexity: O(C(n,k))
 * Space Complexity: O(k)
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה רקורסיבית ליצירת כל הקומבינציות האפשריות
// אלגוריתם: Backtracking - בחירה או אי-בחירה של כל מספר
void rec(int n, int k, ARR<ARR<int>>& res, ARR<int>& combin, int count, int number)
{
    if(count==k)
    {
        res.elements.push_back(combin); // הוספת הקומבינציה המלאה לתוצאות
        return;
    }
    if(number>n)
        return; // חרגנו מהטווח
        
    // אפשרות 1: לכלול את המספר הנוכחי בקומבינציה
    combin.elements.push_back(number);
    rec(n, k, res, combin, count+1, number+1);
    combin.elements.pop_back(); // Backtracking - הסרת המספר
    
    // אפשרות 2: לא לכלול את המספר הנוכחי בקומבינציה
    rec(n, k, res, combin, count, number+1);
}

// פונקציה ראשית ליצירת כל הקומבינציות של k מספרים מהטווח [1, n]
ARR<ARR<int>> combinations(int n, int k)
{
    ARR<ARR<int>> res; // מערך התוצאות
    if(n<1 || k==0)
        return res; // מקרי קצה
        
    ARR<int> combin; // הקומבינציה הנוכחית
    
    rec(n, k, res, combin, 0, 1); // התחלת החיפוש הרקורסיבי
    return res; // החזרת כל הקומבינציות
}