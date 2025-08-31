/*
 * Problem: Given a string s, partition it such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
 * A palindrome is a string that reads the same forward and backward.
 * 
 * Example:
 * Input: s = "aab"
 * Output: [["a","a","b"],["aa","b"]]
 * Explanation: There are two partitions of the string "aab" where every substring is a palindrome: "a", "a", "b" and "aa", "b".
 * 
 * Input: s = "a"
 * Output: [["a"]]
 * Explanation: The only partition of the string "a" is itself, which is a palindrome.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה מחרוזת, חלק אותה כך שכל תת-מחרוזת בחלוקה היא פלינדרום, החזר את כל החלוקות האפשריות
 * 
 * Time Complexity: O(n * 2^n)
 * Space Complexity: O(n)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה עזר לבדיקה אם תת-מחרוזת היא פלינדרום
bool is_palindrome(string& s, int start, int end)
{
    if(start>end)
        return false; // טווח לא תקין
    
    end--; // התאמה לאינדקס האחרון
    while(start<end)
    {
        if(s[start]!=s[end])
            return false; // לא פלינדרום
        start++;
        end--;
    }
            
    return true; // פלינדרום
}

// פונקציה רקורסיבית למציאת כל החלוקות האפשריות
// אלגוריתם: Backtracking - ניסיון כל החלוקות האפשריות עם חזרה לאחור
void rec(string s, int index, ARR<ARR<string>>& res, ARR<string>& part)
{
    int len=s.length();
    if(len<=index)
    {
        res.elements.push_back(part); // הוספת החלוקה הנוכחית לתוצאות
        return;
    }
    
    // ניסיון כל התת-מחרוזות האפשריות מהאינדקס הנוכחי
    for(int i=index+1; i<=len; i++)
        if(is_palindrome(s, index, i)) // אם התת-מחרוזת היא פלינדרום
        {
            part.elements.push_back(s.substr(index, i-index)); // הוספה לחלוקה הנוכחית
            rec(s, i, res, part); // המשך רקורסיבי
            part.elements.pop_back(); // Backtracking - הסרת ההוספה הנוכחית
        }
}

// פונקציה ראשית למציאת כל החלוקות הפלינדרומיות של מחרוזת
ARR<ARR<string>> palindrome_partition(string s) 
{
    ARR<ARR<string>> res; // מערך התוצאות
    
    ARR<string> part; // החלוקה הנוכחית
    rec(s, 0, res, part); // התחלת החיפוש הרקורסיבי
    return res; // החזרת כל החלוקות שנמצאו
}