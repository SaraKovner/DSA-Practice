/*
 * Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
 * A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
 * (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
 *  Example 1        Input: s = "abc", t = "ahbgdc"
 *         Output: true
 *     Example 2        Input: s = "axc", t = "ahbgdc"
 *         Output: false
 * 
 * Difficulty: 🟢 Easy
 * 
 * תרגום: בדוק אם מחרוזת s היא תת-רצף של מחרוזת t
 * 
 * Time Complexity: O(n) - אורך המחרוזת t
 * Space Complexity: O(1)
 */
#include "Question.h"

// פונקציה ראשית לבדיקת אם מחרוזת היא תת-רצף של אחרת
// אלגוריתם: Two Pointers - מעבר על שתי המחרוזות במקביל
STR  check_subsequence(STR  s, STR  t)
{
    if(s==NULL || strlen(s)==0)
        return STR_Copy("true");  // מחרוזת ריקה תמיד תת-רצף
    if(t==NULL)
        return STR_Copy("false"); // לא יכול למצוא תת-רצף במחרוזת NULL
        
    char* ptr_s=s, *ptr_t=t;
    
    // אלגוריתם Two Pointers: מעבר על t ומתקדם ב-s רק כשמוצא התאמה
    while(*ptr_t!='\0')
    {
        // מצאנו תו זהה אז התקדמות על שני המחרוזות במקביל
        if(*ptr_s==*ptr_t)
        {
            ptr_s++;  // מתקדם ב-s רק כשמוצא התאמה
            ptr_t++;
        }
        else
            ptr_t++;  // תמיד מתקדם ב-t
    }
    
    // אם סיימנו את s באופן מלא - זה תת-רצף
    if(*ptr_s=='\0')
        return STR_Copy("true");
        
    return STR_Copy("false");
}
