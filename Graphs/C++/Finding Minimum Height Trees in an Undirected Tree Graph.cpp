/*
 * Problem: A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree. 
 * Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, 
 * you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e., min(h)) are called minimum height trees (MHTs).
 * 
 * Example 1:
 * Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
 * Output: [1]
 * Explanation: Choosing node 1 as the root, the height of the tree is 1 which is the minimum.
 * 
 * Example 2:
 * Input: n = 6, edges = [[3, 0], [3, 1], [3, 2], [3, 4], [5, 4]]
 * Output: [3, 4]
 * 
 * Constraints:
 * 1 <= n <= 2 * 10^4
 * edges.length == n - 1
 * 0 <= ai, bi < n
 * All the pairs (ai, bi) are distinct.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון עץ לא מכוון, מצא את הצמתים שכאשר נבחרים כשורש יוצרים עץ עם גובה מינימלי
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;
#include <queue>
#include <algorithm>

// פונקציה עזר לביצוע BFS ממקור נתון
vector<int> bfs(int start, const vector<vector<int>>& graph)
{
    int n=graph.size();
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> distance(n, -1); // וקטור לשמירת המרחקים
   
    q.push(start);
    visited[start]=true; // סימון נקודת ההתחלה כמבוקרת
    distance[start]=0;
    
    // BFS סטנדרטי
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        
        for(int neighbor: graph[node])
        {
            if(!visited[neighbor])
            {
                distance[neighbor]=distance[node]+1; // עדכון המרחק
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
    
    return distance;
}

// פונקציה ראשית למציאת עצי גובה מינימלי
// אלגוריתם: מציאת קוטר העץ ובחירת הצמתים במרכזו
ARR<int> minimum_htrees(int n, ARR<ARR<int>> edges)
{
    // בניית רשימת סמיכות לייצוג הגרף
    vector<vector<int>> graph(n);
    
    for(int i=0; i<edges.elements.size(); i++)
    {
        int a=edges[i][0];
        int b=edges[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a); // גרף לא מכוון
    }
    
    // מציאת עלה כנקודת התחלה
    int start=0;
    for(int i=0; i<n; i++)
        if(graph[i].size()==1)
        {
            start=i;
            break;
        }
    
    // BFS ראשון למציאת הצומת הרחוק ביותר מנקודת ההתחלה
    vector<int> dist1=bfs(start, graph);
    
    // מציאת הצומת הרחוק ביותר (קצה אחד של הקוטר)
    int u=0;
    for(int i=0; i<n; i++)
        if(dist1[i]>dist1[u])
            u=i;
        
    // BFS שני למציאת הקוטר והקצה השני
    vector<int> dist2=bfs(u, graph);
    int v=0;
    for(int i=0; i<n; i++)
        if(dist2[i]>dist2[v])
            v=i;
            
    // BFS שלישי לחישוב מרחקים מהקצה השני
    vector<int> dist3=bfs(v, graph);
    int diameter=dist2[v]; // אורך הקוטר
    
    // מציאת הצמתים במרכז הקוטר (MHT roots)
    ARR<int> res;
    for(int i=0; i<n; i++)
        if(dist2[i]==diameter/2 || dist3[i]==diameter/2)
            res.elements.push_back(i);
    
    return res; // החזרת שורשי עצי הגובה המינימלי
}