/*
 * Problem Description:
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
 * 
 * Example 1:
 *     Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *     Output: 6
 * 
 * Example 2:
 *     Input: height = [4,2,0,3,2,5]
 *     Output: 9
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: לכידת מי גשם - חישוב כמות המים שניתן ללכוד בין קירות בגבהים שונים
 * 
 * Time Complexity: O(n) - מעבר יחיד על המערך (פעמיים במקרה הרע)
 * Space Complexity: O(1) - שימוש במשתנים קבועים בלבד
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה ראשית לחישוב כמות המים שניתן ללכוד אחרי גשם
// אלגוריתם: מעבר דו-כיווני עם חיפוש קירות תומכים
int trapping_rain_water(ARR<int> height) 
{
    int n = height.elements.size();
    
    // מקרי קצה: מערך ריק או עם קיר אחד - לא ניתן ללכוד מים
    if(n == 0 || n == 1)
        return 0;
        
    int res = 0;    // סה"כ המים שנלכדו
    int temp = 0;   // מים זמניים בין קירות
    int index = 0;  // אינדקס הקיר השמאלי התומך הנוכחי

    // מעבר ראשון: משמאל לימין - חיפוש אגנים שניתן למלא במים
    for(int i = 1; i < n; i++)
    {
        if(height[index] > height[i]) // אם הקיר השמאלי גבוה יותר - ניתן ללכוד מים
            temp += height[index] - height[i]; // צבירת מים זמנית
        else // מצאנו קיר גבוה/שווה - סגירת האגן
        {
            res += temp;  // הוספת המים שנלכדו לתוצאה הסופית
            temp = 0;     // איפוס המים הזמניים
            index = i;    // עדכון הקיר השמאלי התומך
        }
    }
    
    // טיפול במקרה שיש שאריות מים בצד ימין
    // זה קורה כשהקיר הגבוה ביותר נמצא באמצע המערך
    if(index < n-1)
    {
        temp = 0;
        int newIndex = n - 1; // התחלה מהקיר הימני ביותר
        
        // מעבר שני: מימין לשמאל עד הקיר הגבוה שמצאנו
        for (int i = n - 2; i >= index; i--)
        {
            if (height[i] < height[newIndex]) // אם הקיר הימני גבוה יותר
                temp += height[newIndex] - height[i]; // צבירת מים
            else
                newIndex = i; // עדכון הקיר הימני התומך
        }
        res += temp; // הוספת המים מהצד הימני
    }
    
    return res; // החזרת סה"כ המים שנלכדו
}
