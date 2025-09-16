/*
 * Description:
 * You are given an array pairs, where pairs[i] = [x_i, y_i], and:
 * There are no duplicates.
 * x_i < y_i.
 * Let ways be the number of rooted trees that satisfy the following conditions:
 * The tree consists of nodes whose values appeared in pairs.
 * A pair [x_i, y_i] exists in pairs if and only if x_i is an ancestor of y_i or y_i is an ancestor of x_i.
 * Return:
 * 0 if ways == 0
 * 1 if ways == 1
 * 2 if ways > 1
 * A rooted tree is a tree that has a single root node, and all edges are oriented to be outgoing from the root.
 * An ancestor of a node is any node on the path from the root to that node (excluding the node itself). The root has no ancestors.
 * 
 * Example:
 * Input: pairs = [[1,2],[2,3]]
 * Output: 1
 * Explanation: There is exactly one valid rooted tree, which is shown in the above figure.
 * 
 * Constraints:
 * 1 <= pairs.length <= 10^5
 * 1 <= x_i < y_i <= 500
 * The elements in pairs are unique.
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: קביעת מספר הדרכים ליצירת עץ מושרש מזוגות צמתים
 * 
 * Time Complexity: O(n^2 * 2^n) - במקרה הגרוע, רקורסיה עם בדיקת כל הצמתים
 * Space Complexity: O(n) - עומק הרקורסיה ומבני נתונים זמניים
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <set>
#include <utility>

// פונקציית עזר רקורסיבית לספירת דרכי יצירת עץ מושרש
// אלגוריתם: Backtracking - בדיקת כל אפשרות לבחירת שורש
int rec(set<int>& nodes, set<pair<int, int>>& pairs)
{
    // מקרה בסיס: אם לא נשארו זוגות - יש דרך אחת לבנות עץ
    if(pairs.empty())
        return 1;
    
    set<int> new_nodes;     // צמתים לשלב הבא
    set<pair<int, int>> new_pairs; // זוגות לשלב הבא
    
    int ways = 0; // מספר הדרכים האפשריות
    
    // בדיקת כל צומת כמועמד לשורש (עד שמוצאים יותר מ-1 דרך)
    for(auto it1 = nodes.begin(); it1 != nodes.end() && ways < 2; it1++)
    {
        int count = 0; // מספר הזוגות שמכילים את הצומת הנוכחי
        
        // ספירת הזוגות שמכילים את הצומת ובניית רשימת השאר
        for(auto it2 = pairs.begin(); it2 != pairs.end(); it2++)
        {
            if(it2->first == *it1 || it2->second == *it1)
                count++; // הצומת משתתף בזוג הזה
            else
            {
                // הזוג לא מכיל את הצומת - נוסיף לשלב הבא
                new_pairs.insert({it2->first, it2->second});
                new_nodes.insert(it2->first);
                new_nodes.insert(it2->second);
            }
        }
        
        // אם הצומת מחובר לכל הצמתים האחרים - הוא יכול להיות שורש
        if(count == nodes.size() - 1)
            ways += rec(new_nodes, new_pairs); // רקורסיה על השאר
        
        // ניקוי לאיטרציה הבאה
        new_nodes.clear();
        new_pairs.clear();
    }
    
    return ways;
}

// פונקציה ראשית לקביעת מספר הדרכים ליצירת עץ מושרש
// אלגוריתם: Graph Theory + Backtracking - בדיקת כל אפשרות לשורש
int reconstruct_tree(ARR<ARR<int>> pairs)
{
    int n = pairs.elements.size();
    set<int> nodes;           // סט של כל הצמתים בעץ
    set<pair<int, int>> p;    // סט של כל הזוגות
    
    // בניית סטים מהקלט
    for(int i = 0; i < n; i++)
    {
        // הוספת כל הצמתים מהזוגות
        nodes.insert(pairs[i][0]);
        nodes.insert(pairs[i][1]);
        // הוספת הזוג לסט הזוגות
        p.insert({pairs[i][0], pairs[i][1]});
    }
    
    // קריאה לפונקציית העזר הרקורסיבית
    int ways = rec(nodes, p);
    
    // החזרת התוצאה לפי הדרישה: 0, 1, או 2 (אם יותר מ-1)
    return ways < 2 ? ways : 2;
}
