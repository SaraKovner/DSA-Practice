/*
 * Problem Description:
 * Given an integer array data representing the data, return whether it is a valid UTF-8 encoding.
 * A character in UTF-8 can be from 1 to 4 bytes long, subjected to the following rules:
 * For a 1-byte character, the first bit is a 0, followed by its Unicode code.
 * For an n-byte character, the first n bits are all one's, the n + 1 bit is 0, followed by n - 1 bytes with the most significant 2 bits being 10.
 * 
 * UTF-8 Encoding Rules:
 *     Number of Bytes   |        UTF-8 Octet Sequence (binary)
 *     ------------------|---------------------------------------
 *            1          |   0xxxxxxx
 *            2          |   110xxxxx 10xxxxxx
 *            3          |   1110xxxx 10xxxxxx 10xxxxxx
 *            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 * 
 * Example 1:
 *     Input: data = [197, 130, 1]
 *     Output: true
 *     Explanation: [11000101, 10000010, 00000001] - valid UTF-8
 * 
 * Example 2:
 *     Input: data = [235, 140, 4]
 *     Output: false
 *     Explanation: [11101011, 10001100, 00000100] - invalid UTF-8
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: בדיקת תקינות קידוד UTF-8 - בדיקה אם מערך מספרים מייצג קידוד UTF-8 תקין
 * 
 * Time Complexity: O(n) - מעבר יחיד על המערך
 * Space Complexity: O(1) - שימוש במשתנים קבועים בלבד
 */

#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <iostream>

// פונקציה ראשית לבדיקת תקינות קידוד UTF-8
// אלגוריתם: בדיקת ביטים לפי כללי UTF-8 עם מעקב אחר מספר בתים צפויים
string utf_validation(ARR<int> data) 
{
    int num, count_4 = 0; // count_4 - מספר בתים נוספים הצפויים
    int mask = 0x80, sub_mask = 0xC0; // מסכות לבדיקת ביטים: 10000000, 11000000
    
    for(int i = 0; i < data.elements.size(); i++)
    {
        num = data[i];
        if((mask & num) != 0) // אם הביט הראשון הוא 1
        {
            count_4 = 1;
            num <<= 1; // הזזה שמאלה לבדיקת הביט הבא
            
            // ספירת כמה ביטים רצופים של 1 יש בתחילת הבית
            while((mask & num) != 0)
            {
                count_4++;
                i++; // מעבר לבית הבא
                
                // בדיקות תקינות: לא יותר מ-4 בתים, לא חריגה מהמערך, בית המשך חייב להתחיל ב-10
                if(count_4 > 4 || i >= data.elements.size() || (sub_mask & data[i]) != 0x80)
                {
                    return "false";
                }
                num <<= 1; // המשך בדיקת הביטים
            }
        }
        // אם הביט הראשון הוא 0 - תו של בית אחד (תקין)
    }
    return "true";  
}
