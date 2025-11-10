/*
 * Description: You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i].
 * Each Ai or Bi is a string that represents a single variable.
 * You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.
 * Return the answers to all queries. If a single answer cannot be determined, return -1.0.
 * Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.
 * Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.
 * 
 * Example 1:
 * Input: equations = [["a", "b"], ["b", "c"]], values = [2.0, 3.0], queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]]
 * Output: [6.0, 0.5, -1.0, 1.0, -1.0]
 * Explanation:
 *         Given: a / b = 2.0, b / c = 3.0
 *         queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 *         returns: [6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: פותר משוואות - מציאת יחסים בין משתנים באמצעות גרף משוקלל
 * 
 * Time Complexity: O(V + E) per query - DFS על הגרף
 * Space Complexity: O(V + E) - אחסון הגרף ומערך הביקור
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <string>
#include <unordered_map>

// פונקציה רקורסיבית לביצוע DFS במטרה למצוא מסלול בין שני משתנים
// מחזירה את המכפלה של כל הקשתות במסלול (התוצאה של החילוק)
double dfsRec(unordered_map<string, vector<pair<string, double>>>& graph,
              const string& current, const string& target,
              unordered_map<string, bool>& visited, double acc) 
{
    if (current == target) return acc; // הגענו ליעד - מחזירים את התוצאה המצטברת
    visited[current] = true; // סימון הצומת הנוכחי כמבוקר
    
    // מעבר על כל השכנים של הצומת הנוכחי
    for (auto& neighbor : graph[current]) {
        const string& next = neighbor.first;  // השכן הבא
        double weight = neighbor.second;       // משקל הקשת (יחס החילוק)

        if (!visited[next]) {
            // המשך החיפוש רקורסיבית עם עדכון המכפלה
            double result = dfsRec(graph, next, target, visited, acc * weight);
            if (result != -1.0) return result; // אם מצאנו מסלול - החזרת התוצאה
        }
    }

    return -1.0; // לא נמצא מסלול מהצומת הנוכחי ליעד
}

// פונקציה ראשית לביצוע DFS בין שני משתנים
// מחזירה את התוצאה של החילוק או -1.0 אם לא ניתן לחשב
double dfs(unordered_map<string, vector<pair<string, double>>>& graph, string& s, string& d)
{
    // בדיקה אם שני המשתנים קיימים בגרף
    if (graph.find(s) == graph.end() || graph.find(d) == graph.end())
        return -1.0; // אחד מהמשתנים לא מוגדר

    unordered_map<string, bool> visited; // מערך ביקור לכל שאילתה
    return dfsRec(graph, s, d, visited, 1.0); // התחלת החיפוש עם מכפלה 1.0
}

// פונקציה ראשית לפתרון משוואות באמצעות גרף משוקלל
// אלגוריתם: בניית גרף דו-כיווני + DFS לכל שאילתה
ARR<double> equation_solver(ARR<ARR<string>> equations, ARR<double> values, ARR<ARR<string>> queries) 
{
    // בניית גרף משוקלל מהמשוואות הנתונות
    unordered_map<string, vector<pair<string, double>>> graph;
    
    for (int i = 0; i < equations.elements.size(); i++) 
    {
        string A = equations[i][0]; // משתנה ראשון
        string B = equations[i][1]; // משתנה שני
        double val = values[i];     // התוצאה של A/B
        
        // הוספת קשתות דו-כיווניות:
        graph[A].push_back({B, val});        // A -> B עם משקל val (A/B = val)
        graph[B].push_back({A, 1.0 / val});  // B -> A עם משקל 1/val (B/A = 1/val)
    }

    // יצירת מערך תוצאות
    ARR<double> res;
    res.elements = vector<double>(queries.elements.size());

    // עיבוד כל השאילתות
    for(int i = 0; i < queries.elements.size(); i++)
        res[i] = dfs(graph, queries[i][0], queries[i][1]);
    
    return res; // החזרת מערך התוצאות
}
