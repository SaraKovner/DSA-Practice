/*
 * Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 *     Input: s = "(()"
 *     Output: 2
 *     Explanation: The longest valid parentheses substring is "()".
 * 
 * Example 2:
 *     Input: s = ")()())"
 *     Output: 4
 *     Explanation: The longest valid parentheses substring is "()()".
 * 
 * Example 3:
 *     Input: s = ""
 *     Output: 0
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מציאת אורך תת-מחרוזת הסוגריים התקינה הארוכה ביותר
 * 
 * Time Complexity: O(n) - שני מעברים על המחרוזת
 * Space Complexity: O(1) - רק משתנים קבועים
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include<stack>

// פונקציה ראשית למציאת אורך תת-מחרוזת סוגריים תקינה ארוכה ביותר
// אלגוריתם: שני מעברים - שמאל לימין וימין לשמאל
int longest_substring(string s)
{
    int start=0, max_length=0, count=0, i;
    
    // מעבר ראשון: משמאל לימין - מטפל ב')' עודפים
    for(i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
            count++; // סוגר פתוח
        if(s[i]==')')
            count--; // סוגר סגור
            
        if(count<0) // יותר ')' מאשר '(' - סיום רצף תקין
        {
            max_length=max(max_length, i-start);
            start=i+1; // התחלה חדשה
            count=0;
        }
    }
    
    if(count<0)
        return max_length;
    
    if(count==0) // כל הסוגריים מאוזנים
        return max(max_length, i-start);
        
    // מעבר שני: מימין לשמאל - מטפל ב'(' עודפים
    int right=s.length()-1;
    count=0;
    for(i=s.length()-1; i>=start; i--)
    {
        if(s[i]=='(')
            count--; // סוגר פתוח (בכיוון הפוך)
        if(s[i]==')')
            count++; // סוגר סגור (בכיוון הפוך)
        
        if(count<0) // יותר '(' מאשר ')' - סיום רצף תקין
        {
            max_length=max(max_length, right-i);
            right=i-1; // התחלה חדשה
            count=0;
        }
    }
    
    if(count==0) // כל הסוגריים מאוזנים
        return max(max_length, right-i);
        
    return max_length;  
}