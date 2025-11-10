/*
 * Description: Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 * The test cases will be generated such that the answer is unique.
 * 
 * Example 1:
 *     Input: s = "ADOBECODEBANC", t = "ABC"
 *     Output: "BANC"
 * 
 * Example 2:
 *     Input: s = "a", t = "a"
 *     Output: "a"
 * 
 * Example 3:
 *     Input: s = "a", t = "aa"
 *     Output: ""
 *     Explanation: Since the length of t is 2 and there is only one 'a' in s, it's impossible to get a substring.
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: חלון מינימלי במחרוזת - מציאת תת-מחרוזת קצרה הכוללת כל תווי מחרוזת המטרה
 * 
 * Time Complexity: O(m + n) - מעבר יחיד על שתי המחרוזות
 * Space Complexity: O(k) - k = מספר התווים הייחודיים ב-t
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// פונקציה עזר למציאת החלון המינימלי באמצעות Sliding Window
// אלגוריתם: Two Pointers עם מעקב אחר תווים בחלון
string func(string& s, string& t)
{
    // ספירת תווים במחרוזת המטרה
    unordered_map<char, int> tCount;
    for (char c : t) {
        tCount[c]++;
    }

    // משתנים למעקב אחר החלון הנוכחי
    unordered_map<char, int> windowCount; // ספירת תווים בחלון הנוכחי
    int have = 0; // כמה סוגי תווים כבר עומדים בדרישה
    int need = tCount.size(); // כמה סוגי תווים צריך להשלים

    // משתנים למעקב אחר התוצאה האופטימלית
    int left = 0, right = 0; // גבולות החלון (מצביעי שמאל וימין)
    int minLen = INT_MAX;    // אורך החלון המינימלי שנמצא
    int minStart = 0;        // מיקום התחלת החלון המינימלי

    // אלגוריתם Sliding Window: הרחבת החלון וצמצום
    while (right < s.length()) {
        char c = s[right]; // התו הנוכחי בגבול הימני
        windowCount[c]++; // הוספת התו לחלון

        // בדיקה אם התו הנוכחי השלים את הדרישה שלו ב-t
        if (tCount.count(c) && windowCount[c] == tCount[c]) {
            have++; // סוג תו נוסף הושלם
        }

        // אם כל התווים הנדרשים נמצאים בחלון - ננסה לצמצם
        while (have == need) {
            // עדכון התוצאה אם נמצא חלון קטן יותר
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            // ניסיון לצמצם את החלון מהשמאל
            char leftChar = s[left];
            windowCount[leftChar]--; // הוצאת התו השמאלי מהחלון
            
            // בדיקה אם הוצאת התו פגעה בדרישה
            if (tCount.count(leftChar) && windowCount[leftChar] < tCount[leftChar]) {
                have--; // סוג תו אחד כבר לא מושלם
            }
            left++; // הזזת גבול החלון השמאלי
        }

        right++; // הרחבת החלון ימינה
    }

    // החזרת התוצאה: חלון מינימלי או מחרוזת ריקה
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

// פונקציה ראשית למציאת חלון מינימלי במחרוזת
// אלגוריתם: Sliding Window Technique עם Two Pointers
string minimum_window_substring(string s, string t)
{
    // בדיקת מקרה קצה: אם המטרה ארוכה מהמקור - אי אפשר
    if(t.length() > s.length())
        return "";
    
    return func(s, t); // קריאה לפונקציית העזר
}
