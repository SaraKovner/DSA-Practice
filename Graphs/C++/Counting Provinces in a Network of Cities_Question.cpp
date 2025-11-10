/*
 * Description: There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c. A province is a group of directly or indirectly connected cities and no other cities outside of the group.
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise. Return the total number of provinces.
 * 
 * Example 1:
 * Input:
 * isConnected = [
 *   [1, 1, 0],
 *   [1, 1, 0],
 *   [0, 0, 1]
 * ]
 * Output: 2
 * Explanation: There are two provinces: one consisting of cities 0 and 1, and another consisting of city 2.
 * 
 * Example 2:
 * Input:
 * isConnected = [
 *   [1, 0, 0],
 *   [0, 1, 0],
 *   [0, 0, 1]
 * ]
 * Output: 3
 * Explanation: There are three provinces, each city is its own province.
 * 
 * Constraints:
 * 1 <= n <= 200
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1 for all i.
 * If isConnected[i][j] == 1, then isConnected[j][i] == 1.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: ספירת מחוזות ברשת ערים - מציאת מספר הרכיבים הקשירים בגרף
 * 
 * Time Complexity: O(n²) - מעבר על כל התאים במטריצה
 * Space Complexity: O(n) - מערך ביקור + מחסנית הרקורסיה
 */
#include "Question.hpp"
#include "Utils.hpp"

// פונקציה רקורסיבית לביצוע DFS וסימון כל הערים הקשורות
// מסמנת את כל הערים הקשורות לעיר הנוכחית כמבוקרות
void dfsRec(ARR<ARR<int>>& isConnected, ARR<int>& visited, int n, int i)
{
    visited[i] = 1; // סימון העיר הנוכחית כמבוקרת
    
    // מעבר על כל הערים האחרות
    for(int j = 0; j < n; j++)
        if (isConnected[i][j] == 1 && visited[j] == 0)
            dfsRec(isConnected, visited, n, j); // ביקור רקורסיבי בעיר הקשורה
}

// פונקציה ראשית לספירת המחוזות באמצעות DFS
// עוברת על כל הערים ומתחילה DFS חדש לכל עיר לא מבוקרת
int dfs(ARR<ARR<int>>& isConnected, ARR<int>& visited, int n)
{
    int count = 0; // מונה המחוזות
    
    // מעבר על כל הערים
    for(int i = 0; i < n; i++)
        if(visited[i] == 0) // אם העיר לא נבדקה עדיין
        {
            count++; // מחוז חדש נמצא
            dfsRec(isConnected, visited, n, i); // סימון כל הערים במחוז זה
        }
        
    return count; // החזרת מספר המחוזות
}

// פונקציה ראשית לספירת מספר המחוזות ברשת ערים
// אלגוריתם: DFS לזיהוי רכיבים קשירים בגרף לא מכוון
int number_of_provinces(ARR<ARR<int>> isConnected) {
    int n = isConnected.elements.size(); // מספר הערים
    
    // יצירת מערך ביקור - כל העמדות מתחילות כ-0 (לא מבוקרות)
    ARR<int> visited;
    visited.elements = std::vector<int>(n, 0);
    
    return dfs(isConnected, visited, n); // החזרת מספר המחוזות
}
