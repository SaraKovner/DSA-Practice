/*
 * Problem: Given a list of non-negative integers, arrange them in such a way that they form the largest possible number and return it as a string. 
 * For example, if the input list is [10, 2], the largest number you can form is "210". The solution must handle very large numbers, so the output should be returned as a string.
 * 
 * Example 1:
 * Input: [10, 2]
 * Output: "210"
 * 
 * Example 2:
 * Input: [3, 30, 34, 5, 9]
 * Output: "9534330"
 * 
 * Example 3:
 * Input: [10]
 * Output: "10"
 * 
 * The goal is to create a function that can efficiently compute this by taking advantage of custom sorting.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונה רשימת מספרים לא שליליים, סדר אותם כך שיוצרים את המספר הגדול ביותר האפשרי
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <algorithm>
using namespace std;

// פונקציית השוואה מותאמת אישית למיון
// משווה איזה סידור של שני מספרים יוצר מספר גדול יותר
bool cmp(int a, int b)
{
    string a_s=to_string(a);
    string b_s=to_string(b);
    
    // בדיקה איזה חיבור גדול יותר: a+b או b+a
    return a_s+b_s < b_s+a_s; // אם a+b < b+a אז b צריך לבוא לפני a
}

// פונקציה ראשית ליצירת המספר הגדול ביותר מרשימת מספרים
// אלגוריתם: Custom Sort - מיון לפי קריטריון מותאם אישית
string largest_number(ARR<int> nums)
{
    // מיון המספרים לפי הקריטריון המותאם אישית
    sort(nums.elements.begin(), nums.elements.end(), cmp);
    
    string s=""; // המחרוזת התוצאה
    
    // בניית המספר הגדול ביותר מהסוף להתחלה (אחרי המיון)
    for(int i=nums.elements.size()-1; i>=0; i--)
        s+=to_string(nums[i]);
    
    // טיפול במקרה מיוחד: אם כל המספרים הם 0
    if(!s.empty() && s[0]=='0')
        return "0";
    
    return s; // החזרת המספר הגדול ביותר כמחרוזת
}