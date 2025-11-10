/*
 * Description: You are given a list of airline tickets where tickets[i] = [from_i, to_i] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
 * All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK".
 * If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
 * For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
 * You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
 * 
 * Example:
 * Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
 * Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
 * 
 * Constraints:
 * 1 <= tickets.length <= 300
 * tickets[i].length == 2
 * from_i.length == 3
 * to_i.length == 3
 * from_i and to_i consist of uppercase English letters.
 * from_i != to_i
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: שחזור מסלול מכרטיסי תעופה - מציאת מסלול אוילרי בסדר לקסיקוגרפי
 * 
 * Time Complexity: O(E log E) - מיון היעדים + DFS
 * Space Complexity: O(E) - אחסון הגרף ומחסנית הרקורסיה
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <string>
#include <algorithm> 
#include <map>
using namespace std;

// פונקציה רקורסיבית לבניית מסלול אוילרי באמצעות DFS
// אלגוריתם Hierholzer למציאת Eulerian Path
void dfs(map<string, multiset<string>>& graph, vector<string>& res, string src)
{
    auto& dests = graph[src]; // רשימת היעדים מהשדה הנוכחי (ממוינת לקסיקוגרפית)
    
    // מעבר על כל היעדים מהשדה הנוכחי
    while (!dests.empty()) 
    {
        string next = *dests.begin(); // בחירת היעד הקטן ביותר לקסיקוגרפית
        dests.erase(dests.begin()); // מסירת הכרטיס כדי לא להשתמש בו שוב
        dfs(graph, res, next); // המשך המסלול רקורסיבית
    }
    
    // הוספת השדה לתוצאה ב-post-order (אחרי סיום כל היעדים ממנו)
    res.push_back(src);
}

// פונקציה ראשית לשחזור מסלול מכרטיסי תעופה
// אלגוריתם: בניית גרף ממוין + מציאת Eulerian Path
ARR<string> reconstruct_itinerary(ARR<ARR<string>> tickets) {
    // בניית גרף מכרטיסי התעופה
    // שימוש ב-multiset למיון אוטומטי בסדר לקסיקוגרפי
    map<string, multiset<string>> graph;
    for (const auto& ticket : tickets.elements) 
        graph[ticket[0]].insert(ticket[1]); // הוספת קשת משדה המקור לשדה היעד
    
    // הרשימות ממוינות אוטומטית בסדר לקסיקוגרפי ב-multiset
    
    vector<string> temp; // מערך זמני לאחסון המסלול
    dfs(graph, temp, "JFK"); // התחלת החיפוש מ-JFK
    reverse(temp.begin(), temp.end()); // היפוך המסלול לסדר הנכון
    
    // העברת התוצאה למבנה ARR
    ARR<string> res;
    res.elements = temp;

    return res; // החזרת המסלול המשוחזר
}
