/*
 * Description: You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections.
 * The inputs are generated such that you can reach any intersection from any other intersection, and there is at most one road between any two intersections.
 * You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel.
 * You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
 * Return the number of ways you can arrive at your destination in the shortest amount of time.
 * Since the answer may be large, return it modulo 109 + 7.
 * 
 * Example 1:
 * Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
 * Output: 4
 * 
 * Example 2:
 * Input: n = 2, roads = [[0,1,10]]
 * Output: 1
 * 
 * Constraints:
 * 1 <= n <= 200
 * n - 1 <= roads.length <= n * (n - 1) / 2
 * roads[i].length == 3
 * 0 <= ui, vi <= n - 1
 * 1 <= timei <= 109
 * ui != vi
 * There is at most one road connecting any two intersections.
 * You can reach any intersection from any other intersection.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מספר הדרכים להגיע ליעד - ספירת מסלולים קצרים בגרף משוקלל
 * 
 * Time Complexity: O((V + E) log V) - אלגוריתם Dijkstra משופר
 * Space Complexity: O(V + E) - אחסון הגרף ומערכי עזר
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <vector>           
#include <queue>           
#include <climits>         
using namespace std;

// אלגוריתם Dijkstra משופר למציאת מספר המסלולים הקצרים
// מחשב באופן זמני גם את המרחקים וגם את מספר המסלולים
int dijkstra(int n, ARR<ARR<int>>& roads)
{
    const int MOD = 1000000007;
    
    // בניית גרף שכנים מהכבישים
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < roads.elements.size(); i++)
    {
        int u = roads[i][0]; // צומת מקור
        int v = roads[i][1]; // צומת יעד
        int w = roads[i][2]; // זמן הנסיעה
        g[u].push_back({v, w}); // כביש דו-כיווני
        g[v].push_back({u, w});
    }

    // אתחול מערכים: מרחקים ומספר מסלולים
    vector<int> distEst(n, INT_MAX); // מרחקים מינימליים מהצומת 0
    vector<int> count(n, 0);         // מספר המסלולים הקצרים לכל צומת

    // תור עדיפויות לאלגוריתם Dijkstra
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // אתחול: מרחק 0 לצומת 0, ויש מסלול אחד אליה
    distEst[0] = 0;
    count[0] = 1;
    pq.push({0, 0}); // {distance, vertex}
    
    // אלגוריתם Dijkstra עם ספירת מסלולים
    while(!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if(d > distEst[u]) continue; // דילוג על עדכונים ישנים

        // עדכון כל השכנים
        for(auto [v, w] : g[u])
        {
            int newDist = d + w; // מרחק חדש דרך הצומת הנוכחי
            
            if(distEst[v] > newDist)
            {
                // נמצא מסלול קצר יותר - עדכון המרחק ואיפוס מספר המסלולים
                distEst[v] = newDist;
                count[v] = count[u]; // מספר המסלולים זהה למספר המסלולים לצומת הקודמת
                pq.push({distEst[v], v});
            }
            else if(distEst[v] == newDist)
            {
                // נמצא מסלול נוסף באותו אורך - הוספת מספר המסלולים
                count[v] = (count[v] + count[u]) % MOD;
            }
        }
    }

    return count[n-1]; // החזרת מספר המסלולים הקצרים לצומת האחרון
}

// פונקציה ראשית לחישוב מספר הדרכים להגיע ליעד
// אלגוריתם: Dijkstra משופר עם ספירת מסלולים
int ways_to_destination(int n, ARR<ARR<int>> roads) {
    return dijkstra(n, roads); // קריאה לאלגוריתם Dijkstra המשופר
}
