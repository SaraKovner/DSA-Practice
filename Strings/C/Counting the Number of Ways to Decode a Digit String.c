/*
 * Problem: A message containing letters from A-Z can be encoded into numbers using the following mapping:
 * 'A' -> "1"
 * 'B' -> "2"
 * ...
 * 'Z' -> "26"
 * 
 * To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
 * "AAJF" with the grouping (1 1 10 6)
 * "KJF" with the grouping (11 10 6)
 * Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
 * Given a string s containing only digits, return the number of ways to decode it.
 * The test cases are generated so that the answer fits in a 32-bit integer.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: הודעה המכילה אותיות A-Z יכולה להיות מקודדת למספרים. נתונה מחרוזת ספרות, החזר את מספר הדרכים לפענח אותה
 * 
 * Example:
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 * 
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1) - אם משתמשים בתכנות דינמי מותאם
 */
#include "Question.h"

int rec(STR* digit, int len, int i)
{
    if(i==len)
        return 1;
        
    if(digit->s[i]=='0')
        return 0;
        
        
    int res=rec(digit, len, i+1);
    
    if(i+1<len)
    {
        //המרה של זוג התווים הבאים למספר כדי לבדוק אם הוא בתווח
        int val=(digit->s[i]-'0')*10+digit->s[i+1]-'0';
        if(val>=10 && val<=26)
            res+=rec(digit, len, i+2);   //כלומר יש גם אפשרות לקחת את הזוג הבא כיצוג בודד
    }
    
    return res;
}

int  count_decode_string_digit_ways(STR  digit)  {
    // if(digit==NULL)
    //     return 0;
    
    
    return rec(&digit, strlen(digit.s)-1, 0);
}
