/*
 * Problem: Given a string containing digits from 2-9 inclusive, your task is to return all possible letter combinations that the number could represent. The order of the combinations does not matter.
 * A mapping of digits to letters (similar to those on telephone buttons) is provided below. Note that the digit 1 does not map to any letters.
 * 
 * Example:
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
 * Explanation:
 * The digit 2 maps to the letters "abc" and the digit 3 maps to the letters "def". By combining these letters, all possible letter combinations are produced.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה מחרוזת ספרות 2-9, החזר את כל הקומבינציות האפשריות של אותיות לפי מיפוי טלפון
 * 
 * Time Complexity: O(3^n * 4^m) where n is digits with 3 letters, m is digits with 4 letters
 * Space Complexity: O(3^n * 4^m)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה רקורסיבית ליצירת כל הקומבינציות האפשריות
// אלגוריתם: Backtracking - בניית כל הקומבינציות באופן רקורסיבי
void rec(string digits, int index, ARR<string>& res, string combin, vector<string>& letters)
{
    if(index==digits.length())
    {
        res.elements.push_back(combin); // הוספת הקומבינציה המלאה לתוצאות
        return;
    }
    
    int digit=digits[index]-'0'; // המרת תו לספרה
    
    // מעבר על כל האותיות המתאימות לספרה הנוכחית
    for(int i=0; i<letters[digit-2].length(); i++)
        rec(digits, index+1, res, combin+letters[digit-2][i], letters);
}

// פונקציה ראשית ליצירת קומבינציות אותיות מספרות טלפון
ARR<string> generate_letter(string digits) 
{
    // מיפוי ספרות לאותיות כמו בטלפון
    vector<string> letters={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    ARR<string> res; // מערך התוצאות
    
    rec(digits, 0, res, "", letters); // התחלת הבניה הרקורסיבית
    
    return res; // החזרת כל הקומבינציות
}