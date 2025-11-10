/*
 * Description: You are given an undirected, weighted, connected graph with n nodes labeled from 1 to n.
 * The graph is represented by an array edges, where edges[i] = [ui, vi, weighti] indicates that there is an edge between nodes ui and vi with weight weighti.
 * A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end, and there is an edge between zi and zi+1 for 0 <= i <= k-1.
 * The distance of a path is the sum of the weights of the edges in the path. Define distanceToLastNode(x) as the shortest distance of a path between node n and node x.
 * A restricted path is a path that satisfies distanceToLastNode(zi) > distanceToLastNode(zi+1) for 0 <= i <= k-1.
 * Return the number of restricted paths from node 1 to node n. Since the number may be large, return it modulo 109 + 7.
 * 
 * Example 1:
 * Input: n = 5, edges = [[1,2,3], [1,3,3], [2,3,1], [1,4,2], [5,2,2], [3,5,1], [5,4,2]]
 * Output: 3
 * 
 * Example 2:
 * Input: n = 4, edges = [[1,3,1], [3,4,1], [1,2,2], [2,4,2]]
 * Output: 1
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מסלולים מוגבלים בגרף משוקלל - ספירת מסלולים עם מרחק יורד לצומת האחרון
 * 
 * Time Complexity: O((V + E) log V + V²) - Dijkstra + DP
 * Space Complexity: O(V + E) - גרף + מערכי עזר
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <queue>
#include <functional>
using namespace std;
#include <climits>

// פונקציה לחישוב מספר המסלולים המוגבלים באמצעות Dynamic Programming
// מסלול מוגבל: המרחק לצומת האחרון יורד בכל צעד
int func(int n, ARR<ARR<int>>& edges, vector<int>& distEst)
{
    const int MOD = 1000000007;

    // בניית גרף שכנים מהקלט
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < edges.elements.size(); i++)
    {
        int u = edges[i][0] - 1; // המרה לאינדקס 0-based
        int v = edges[i][1] - 1;
        int w = edges[i][2];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // מיון הצמתים לפי המרחק לצומת האחרון (מהקטן לגדול)
    vector<int> order(n);
    for(int i = 0; i < n; i++) order[i] = i;

    sort(order.begin(), order.end(),
         [&](int a, int b){ return distEst[a] < distEst[b]; });

    // dp[u] = מספר המסלולים המוגבלים מצומת u לצומת האחרון
    vector<long long> dp(n, 0);
    dp[n-1] = 1; // מהצומת האחרון לעצמו יש מסלול אחד

    // עיבוד הצמתים לפי סדר המרחקים (מהקטן לגדול)
    for(int u : order)
    {
        for(auto& p : g[u])
        {
            int v = p.first;
            // אם המרחק של השכן קטן יותר - זה מסלול מוגבל חוקי
            if(distEst[v] < distEst[u])
            {
                dp[u] = (dp[u] + dp[v]) % MOD;
            }
        }
    }

    // החזרת מספר המסלולים מהצומת הראשון לאחרון
    return dp[0];
}

// אלגוריתם Dijkstra למציאת המרחקים הקצרים מהצומת האחרון לכל הצמתים
vector<int> dijkstra(int n, ARR<ARR<int>> &edges)
{
    // בניית גרף שכנים
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < edges.elements.size(); i++)
    {
        int u = edges[i][0] - 1; // המרה לאינדקס 0-based
        int v = edges[i][1] - 1;
        int w = edges[i][2];
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    // אתחול מערך המרחקים
    vector<int> distEst(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    distEst[n-1] = 0; // התחלה מהצומת האחרון
    pq.push({0, n-1});

    // אלגוריתם Dijkstra הסטנדרטי
    while(!pq.empty())
    {
        auto [d, u] = pq.top(); pq.pop();
        if(d > distEst[u]) continue; // דילוג על עדכונים ישנים

        // עדכון המרחקים לכל השכנים
        for(auto [v, w] : g[u])
        {
            if(distEst[v] > d + w)
            {
                distEst[v] = d + w;
                pq.push({distEst[v], v});
            }
        }
    }

    return distEst; // החזרת מערך המרחקים
}

// פונקציה ראשית לחישוב מספר המסלולים המוגבלים
// אלגוריתם: Dijkstra + Dynamic Programming על גרף DAG
int restricted_path(int n, ARR<ARR<int>> edges) {
    vector<int> distEst = dijkstra(n, edges); // חישוב המרחקים הקצרים
    return func(n, edges, distEst); // חישוב מספר המסלולים המוגבלים
}
