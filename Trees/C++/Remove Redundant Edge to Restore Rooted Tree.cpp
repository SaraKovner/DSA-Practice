/*
 * In this problem, a rooted tree is a directed graph such that there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
 * The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added.
 * The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
 * The resulting graph is given as a 2D-array of edges.
 * Each element of edges is a pair [u_i, v_i] that represents a directed edge connecting nodes u_i and v_i, where u_i is a parent of child v_i.
 * Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes.
 * If there are multiple answers, return the answer that occurs last in the given 2D-array.
 * 
 * Example:
 * Given edges = [[1,2], [1,3], [2,3]], the edge that can be removed to restore the rooted tree is [2, 3].
 * 
 * Constraints:
 * n == edges.length
 * 3 <= n <= 1000
 * edges[i].length == 2
 * 1 <= u_i, v_i <= n
 * u_i != v_i
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: הסרת קשת מיותרת לשחזור עץ מכוון
 * 
 * Time Complexity: O(n) - מעבר אחד על הקשתות עם Union-Find
 * Space Complexity: O(n) - מערכי parent ו-realParent
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציית עזר ל-Union-Find: מוצאת את השורש המשותף עם Path Compression
int find(vector<int>& parent, int x)
{
    if(parent[x]!=x)
        parent[x]=find(parent, parent[x]); // דחיסת נתיב
        
    return parent[x];
}

// פונקציית עזר ל-Union-Find: איחוד שתי קבוצות
// מחזירה false אם נוצר מעגל (הצמתים כבר מחוברים)
bool unionSet(vector<int>& parent, int u, int v)
{
    int pu=find(parent, u); // שורש של u
    int pv=find(parent, v); // שורש של v
    if(pu==pv)
        return false; // יש מעגל - הם כבר מחוברים
        
    parent[pv]=pu; // איחוד הקבוצות
    return true;
}


// פונקציה ראשית למציאת הקשת המיותרת להסרה
// אלגוריתם: Union-Find עם טיפול בשני מקרים - צומת עם שני אבות או מעגל
ARR<int> redundant_connection(ARR<ARR<int>> edges)
{
    int n=edges.elements.size();
    vector<int> parent(n+1); // ל-Union-Find
    vector<int> realParent(n+1, 0); // למעקב אחר הורים אמיתיים
    vector<int> cand1, cand2; // מועמדים להסרה
    
    // שלב 1: בדיקה האם יש צומת עם שני אבות
    for(int i=0; i<n; i++)
    {
        int u=edges[i][0], v=edges[i][1];
        if(realParent[v]==0)
            realParent[v]=u; // אם לא קיים לצומת הזה אב - זה האב הראשון
        else
        {
            // אם יש שני אבות - שמירת שני המועמדים
            cand1={realParent[v], v}; // הקשת הראשונה
            cand2=edges[i].elements;  // הקשת השנייה
            edges[i][1]=0; // סימון שדילגנו על הקשת הזו
        }
    }
    
    // אתחול Union-Find: כל צומת היא הורה של עצמה
    for(int i=1; i<=n; i++)
        parent[i]=i;
        
    // שלב 2: בדיקת מעגלים ואיחוד צמתים
    for(int i=0; i<n; i++)
    {
        int u=edges[i][0], v=edges[i][1];
        if(v==0)
            continue; // דילוג על הקשת שסומנה
        
        if(!unionSet(parent, u,v)) // אם לא ניתן לאחד - יש מעגל
        {
            // אם לא היו שני הורים - זו הקשת הבעייתית
            if(cand1.empty())
                return edges[i];
            
            // יש גם שני הורים וגם מעגל - נחזיר את הראשונה
            ARR<int> res;
            res.elements=cand1;
            return res;
        }
    }
    
    // אם לא היה מעגל - נחזיר את הקשת השנייה שעליה דלגנו
    ARR<int> res;
    res.elements=cand2;
    return res;  
}
