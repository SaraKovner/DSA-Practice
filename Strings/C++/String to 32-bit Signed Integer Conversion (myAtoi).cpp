/*
 * Problem: Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.
 * Algorithm:
 * Whitespace: Ignore any leading whitespace (" ").
 * Signedness: Determine the sign by checking if the next character is '-' or '+'. Assume the number is positive if neither is present.
 * Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
 * Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
 * Return the integer as the final result.
 * 
 * Example 1:
 * Input: s = "42"
 * Output: 42
 * 
 * Example 2:
 * Input: s = "words and 987"
 * Output: 0
 * 
 * Example 3:
 * Input: s = "-91283472332"
 * Output: -2147483648
 * 
 * Constraints:
 * The input string can contain any characters.
 * Only the leading portion of the string that can be interpreted as an integer will be considered.
 * The string length is within the range [0, 200].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מימוש פונקציה להמרת מחרוזת למספר שלם 32-ביט עם טיפול בגלישות וסימנים
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <climits>

// פונקציה ראשית להמרת מחרוזת למספר שלם 32-ביט
// אלגוריתם: עיבוד שלב אחר שלב - רווחים, סימן, ספרות, בדיקת גלישה
int string_to_int(std::string s)
{
    int i=0, num=0, sing=1, n=s.length(); // אינדקס, מספר, סימן, אורך
    
    // שלב 1: דילוג על רווחים מובילים
    for( ; i<n && s[i]==' '; i++);
    
    // שלב 2: טיפול בסימן (+ או -)
    if(i<n && (s[i]=='-' || s[i]=='+'))
    {
        sing=s[i]=='-' ? -1 : 1; // קביעת הסימן
        i++;
    }
    
    // שלב 3: המרת ספרות עד לתו לא-ספרתי
    for( ; i<s.length(); i++)
    {
        if(s[i]<'0' || s[i]>'9')
            return num; // עצירה בתו לא-ספרתי
            
        int digit=s[i]-'0'; // המרת תו לספרה
        
        // שלב 4: בדיקת גלישה לפני הכפלה ב-10
        if(num>(INT_MAX-digit)/10)
            return sing==1 ? INT_MAX : INT_MIN; // החזרת גבול מתאים
            
        num=num*10+digit; // הוספת הספרה למספר
    }
        
    return num*sing; // החזרת המספר עם הסימן הנכון
}