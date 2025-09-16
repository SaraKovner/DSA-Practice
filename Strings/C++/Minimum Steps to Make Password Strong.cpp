/*
 * A password is considered strong if the following conditions are all met:
 * It has at least 6 characters and at most 20 characters.
 * It contains at least one lowercase letter, at least one uppercase letter, and at least one digit.
 * It does not contain three repeating characters in a row (e.g., "Baaabb0" is weak, but "Baaba0" is strong).
 * Given a string password, return the minimum number of steps required to make password strong.
 * If the password is already strong, return 0.
 * In one step, you can:
 * Insert one character into password,
 * Delete one character from password, or
 * Replace one character of password with another character.
 * 
 * Example:
 * Given password = "aA1", the minimum number of steps required to make the password strong is 3.
 * 
 * Constraints:
 * 1 <= password.length <= 50
 * password consists of letters, digits, dot '.' or exclamation mark '!'.
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מספר צעדים מינימלי להפיכת סיסמה לחזקה
 * 
 * Time Complexity: O(n) - מעבר אחד על המחרוזת
 * Space Complexity: O(1) - משתנים קבועים בלבד
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <algorithm>

// פונקציה ראשית לחישוב צעדים מינימליים להפיכת סיסמה לחזקה
// אלגוריתם: Greedy - טיפול בכל בעיה בנפרד ושילוב אופטימלי
int password_checker(string password) 
{
    // הסרת רווחים (ניקוי קלט)
    password.erase(remove(password.begin(), password.end(), ' '), password.end());
    
    // דגלים לבדיקת סוגי תווים (1 = חסר, 0 = קיים)
    int has_lower = 1, has_upper = 1, has_digit = 1;
    int insertions = 0, deletion = 0, replacements = 0;
    
    int n = password.length();
    
    // בדיקת אורך הסיסמה
    if(n < 6)
        insertions = 6 - n; // צריך להוסיף תווים
    if(n > 20)
        deletion = n - 20;  // צריך למחוק תווים
   
    // מעבר על הסיסמה לבדיקת סוגי תווים ורצפים חוזרים
    int i = 0;
    while(i < n)
    {
        // בדיקת סוג התו הנוכחי
        if(password[i] >= 'a' && password[i] <= 'z')
            has_lower = 0; // מצאנו אות קטנה
        if(password[i] >= 'A' && password[i] <= 'Z')
            has_upper = 0; // מצאנו אות גדולה
        if(password[i] >= '0' && password[i] <= '9')
            has_digit = 0; // מצאנו ספרה
        
        // מציאת אורך הרצף החוזר הנוכחי
        int j;
        for(j = i; j < n && password[j] == password[i]; j++);

        int count = j - i; // אורך הרצף
        if(count >= 3)
            replacements += count / 3; // כל 3 תווים זהים דורשים החלפה אחת
        
        i = j; // מעבר לתו הבא שונה
    }
    
    // חישוב מספר סוגי התווים החסרים
    int missing_types = has_lower + has_upper + has_digit;
    
    // מקרה 1: סיסמה קצרה מדי (< 6 תווים)
    if(n < 6)
        return max(insertions, missing_types); // מקסימום בין הוספות לסוגים חסרים
    
    // מקרה 2: סיסמה באורך תקין (6-20 תווים)
    if(n <= 20)
        return max(replacements, missing_types); // מקסימום בין החלפות לסוגים חסרים
    
    // מקרה 3: סיסמה ארוכה מדי (> 20 תווים)
    // מחיקות יכולות לפתור גם בעיות של רצפים חוזרים
    int reduced_replacements = max(0, replacements - deletion);
    return deletion + max(reduced_replacements, missing_types);
}