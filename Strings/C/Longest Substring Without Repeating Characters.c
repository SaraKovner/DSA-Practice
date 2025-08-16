/*
 * Finding the Length of the Longest Substring Without Repeating CharactersQuestion:
 * Given a string s, determine the length of the longest substring within it that does not contain any repeating characters.
 * Examples:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The longest substring without repeating characters is "abc", with a length of 3.
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The longest substring without repeating characters is "b", with a length of 1.
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The longest substring without repeating characters is "wke", with a length of 3. Note that "pwke" is a subsequence, not a substring.
 * Constraints:
 * 0 ≤ length of s ≤ 5 × 10^4
 * s consists of ASCII chars only.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מצא את אורך תת-המחרוזת הארוכה ביותר ללא תווים חוזרים
 * 
 * Time Complexity: O(n) - Sliding Window
 * Space Complexity: O(n) - Set לשמירת תווים
 */
#include "Question.h"


// פונקציה ראשית למציאת אורך תת-המחרוזת הארוכה ביותר ללא תווים חוזרים
// אלגוריתם: Sliding Window עם Set לזיהוי כפילויות
int  longest_substring(STR  s)  
{
    if(s==NULL || s[0]=='\0')
        return 0;
        
    int n=strlen(s); 
    // ניקוי תווים לבנים מסוף המחרוזת
    for( ; n>0 && (s[n-1]==' ' || s[n-1]=='\n'); n--);
    
    Set* set=Set_Create(n);
    
    char* left=s, *right=s;
    int max_length=0;
    
    // אלגוריתם Sliding Window: חלון נע עם שני מצביעים
    while(right-s<n)
    {
        if(Set_Contains(set, *right))
        {
            // אם התו הופיע אז נקדם את המצביע השמאלי עד אחרי התו הזה, כדי לבדוק עוד סדרות
            while(*left!=*right)
            {
                Set_Remove(set, *left);
                left++;
            }
             
            // הסרת התו עצמו   
            Set_Remove(set, *left);
            left++;
        }
        
        Set_Add(set, *right);  // הוספת התו הנוכחי לחלון
        right++;               // הרחבת החלון ימינה
        
        // עדכון האורך המקסימלי
        if(max_length<right-left)
            max_length=right-left;
    }

    return max_length;  
}
