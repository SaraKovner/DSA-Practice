/*
 * Description: Given a total of numCourses courses labeled from 0 to numCourses - 1, and an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai, return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.
 * 
 * Example 1:
 * 
 * Input: numCourses = 2, prerequisites = [[1, 0]]
 * Output: [0, 1]
 * Explanation: To take course 1 you should have finished course 0. So the correct course order is [0, 1].
 *  
 * 
 * Example 2:
 * 
 * Input: numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
 * Output: [0, 2, 1, 3]
 * Explanation: There are multiple valid answers. One correct order is [0, 2, 1, 3]. Another correct order is [0, 1, 2, 3].
 *  
 * 
 * Example 3:
 * 
 * Input: numCourses = 1, prerequisites = []
 * Output: [0]
 * Explanation: There are no prerequisites, so you can take any course.
 *  
 * 
 * Constraints:
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= 5000
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * All the pairs are unique.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מספר קורסים ומערך דרישות קדם, החזר סדר לקיחת הקורסים או מערך ריק אם אי אפשר
 * 
 * Time Complexity: O(V + E) - מיון טופולוגי
 * Space Complexity: O(V + E)
 */
//#define ARR_DATA_TYPE int
#include "Question.h"

// פונקציית עזר למציאת צומת עם דרגת כניסה 0 (ללא תלויות)
int posision_of_0(int * arr, int len)
{
    for(int i=0; i<len; i++)
        if(arr[i]==0)
            return i;
            
    return -1; // לא נמצא צומת עם דרגת כניסה 0
}

// מיון טופולוגי (Topological Sort) באמצעות אלגוריתם Kahn
ARR* topSort(int numCourses, ARR* prerequisites)
{
    // אתחול מערך דרגות כניסה לכל קורס
    int* integree=(int*)calloc(numCourses, sizeof(int));
    uint64_t d[1]={numCourses};
    ARR* sorted=ARR_Create(d, 1); // מערך תוצאה ממוין
    int index_sorted=0, index_0;
    
    // חישוב דרגת הכניסה של כל קורס (כמה קורסים תלויים בו)
    for(int i=0; i<numCourses; i++)
        for(int j=0; j<prerequisites->total_size; j+=2)
            if(prerequisites->data[j]==i) // קורס i תלוי בקורס אחר
                integree[i]++;
                
    while((index_0=posision_of_0(integree, numCourses))!=-1)
    {
        sorted->data[index_sorted++]=index_0;
        integree[index_0]=-1; // סימון שהקורס כבר נוסף למערך הממוין
        
        //עדכון הקודקודים שנכנסה אליהם קשת מהקודקוד הנוכחי
        for(int i=0; i<prerequisites->total_size; i+=2)
            if(prerequisites->data[i+1]==index_0)    //כלומר הקשת היוצאת מהקודוק הנוכחי לקודוק אחר
                integree[prerequisites->data[i]]--;     //הורדת דרגת הכניסה
    }
        
        
    // בדיקה אם נותרו קורסים עם דרגת כניסה > 0 (מעגל בגרף)
    for(int i=0; i<numCourses; i++)
        if(integree[i]>0)
        {
            // אם יש מעגל - החזר מערך ריק
            sorted->dimensions[0]=0;
            free(sorted->data);
            sorted->data=NULL;
            sorted->total_size=0;
            break;
        }
        
    free(integree);
    return sorted;
}

// פונקציה ראשית לתזמון קורסים עם דרישות קדם
ARR* course_scheduling(int  numCourses, ARR  *  prerequisites) 
{
    return topSort(numCourses, prerequisites);  
}
