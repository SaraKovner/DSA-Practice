/*
 * Description: Given a total of numCourses courses labeled from 0 to numCourses - 1, and an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
 * Return true if you can finish all courses. Otherwise, return false.
 *  
 * Example 1:
 * Input: numCourses = 2, prerequisites = [[1, 0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 *  
 * Example 2:
 * Input: numCourses = 2, prerequisites = [[1, 0], [0, 1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should have finished course 1. This creates a cycle, so it is not possible.
 *  
 * Constraints:
 * 1 <= numCourses <= 10^5
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs are unique.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: בדוק אם אפשר לסיים את כל הקורסים עם דרישות מוקדמות
 * 
 * Time Complexity: O(V + E) - Topological Sort
 * Space Complexity: O(V) - מערך דרגות כניסה
 */
#include "Question.h"

// פונקציית עזר למציאת צומת עם דרגת כניסה 0
int posision_of_0(int * arr, int len)
{
    for(int i=0; i<len; i++)
        if(arr[i]==0)
            return i;
            
    return -1;
}

// פונקציית עזר לביצוע מיון טופולוגי (Kahn's Algorithm)
// אלגוריתם: מיון טופולוגי לזיהוי מעגלים
int topSort(int numCourses, ARR* prerequisites)
{
    int* integree=(int*)calloc(numCourses, sizeof(int));

    //חישוב דרגת הכניסה של כל קודוקד
    //עבור כל קורס נחשב את מספר הכניסות עליו לפי הדרישות
    for(int j=0; j<prerequisites->total_size; j+=2)
        integree[prerequisites->data[j]]++;
         
    int visited=0, index=0;       
    while((index=posision_of_0(integree, numCourses))!=-1)
    {
        visited++;  //הגענו לעוד קורס
        integree[index]=-1;   //כבר הכנסנו אותו למערך
        
        //עדכון הקודקודים שנכנסה אליהם קשת מהקודקוד הנוכחי
        for(int k=0; k<prerequisites->total_size; k+=2)
            if(prerequisites->data[k+1]==index)    //כלומר הקשת היוצאת מהקודוק הנוכחי לקודוק אחר
                integree[prerequisites->data[k]]--;     //הורדת דרגת הכניסה של הקודקוד השני
    }
        
    free(integree);
    return visited==numCourses;
}

// פונקציה ראשית לבדיקת אם אפשר לסיים את כל הקורסים
// אלגוריתם: מיון טופולוגי לזיהוי מעגלים בגרף מושה
STR  course_completion(int  numCourses, ARR  *  prerequisites) 
{
    if(topSort(numCourses, prerequisites)==1)
        return STR_Copy("true");
        
    return STR_Copy("false");
}
