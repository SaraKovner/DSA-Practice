/*
 * Problem Description:
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
 * Each number in candidates may only be used once in the combination.
 * Note: The solution set must not contain duplicate combinations.
 * 
 * Example:
 * 
 * Input: candidates = [10, 1, 2, 7, 6, 1, 5], target = 8
 * Output: [[1, 1, 6], [1, 2, 5], [1, 7], [2, 6]]
 * 
 * Input: candidates = [2, 5, 2, 1, 2], target = 5
 * Output: [[1, 2, 2], [5]]
 * 
 * Explanation:
 * For the input [10, 1, 2, 7, 6, 1, 5], target = 8, the unique combinations are [1, 1, 6], [1, 2, 5], [1, 7], and [2, 6].
 * For the input [2, 5, 2, 1, 2], target = 5, the unique combinations are [1, 2, 2] and [5].
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מציאת צירופים ייחודיים שסכומם שווה למטרה (כל מספר ניתן לשימוש פעם אחת בלבד)
 * 
 * Time Complexity: O(2^n) - במקרה הרע בודקים כל צירוף אפשרי
 * Space Complexity: O(target) - עומק הרקורסיה ומערך הצירוף הנוכחי
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <algorithm>
#include <vector>

// פונקציה רקורסיבית למציאת כל הצירופים האפשריים
// אלגוריתם Backtracking עם דילוג על כפילויות
void rec(ARR<int>& candidates, int start, int target, vector<int>& comb, ARR<ARR<int>>& all_comb) 
{
    // מקרה בסיס: אם הגענו למטרה - שמירת הצירוף
    if (target == 0) 
    {
        ARR<int> a;
        a.elements = comb;
        all_comb.elements.push_back(a); // צירוף תקין שסכומו שווה למטרה
        return;
    }
    
    // מעבר על כל המועמדים האפשריים החל מ-start
    for (int i = start; i < candidates.elements.size(); ++i) 
    {
        // דילוג על כפילויות סמוכות כדי למנוע צירופים זהים
        if (i > start && candidates.elements[i] == candidates.elements[i - 1]) 
            continue;
        
        // אופטימיזציה: אם המספר גדול מהמטרה הנותרת - עצירה
        if (candidates.elements[i] > target) 
            break; // המערך ממוין, לכן כל המספרים הבאים גם גדולים מדי
    
        // הוספת המספר לצירוף הנוכחי
        comb.push_back(candidates.elements[i]);
        // קריאה רקורסיבית: i+1 כי כל מספר ניתן לשימוש פעם אחת בלבד
        rec(candidates, i + 1, target - candidates.elements[i], comb, all_comb);
        // Backtrack: הסרת המספר מהצירוף לפני המשך הלולאה
        comb.pop_back(); 
    }
}

// פונקציה ראשית למציאת צירופים ייחודיים שסכומם שווה למטרה
// אלגוריתם: מיון + Backtracking עם דילוג על כפילויות
ARR<ARR<int>> combination_sum(ARR<int> candidates, int target) 
{
    ARR<ARR<int>> res;  // מערך כל הצירופים התקינים
    vector<int> comb;   // צירוף נוכחי בבנייה
        
    // מיון המועמדים כדי לאפשר דילוג על כפילויות ואופטימיזציה
    sort(candidates.elements.begin(), candidates.elements.end());

    rec(candidates, 0, target, comb, res); // התחלת החיפוש הרקורסיבי
    
    return res; // החזרת כל הצירופים התקינים
}
