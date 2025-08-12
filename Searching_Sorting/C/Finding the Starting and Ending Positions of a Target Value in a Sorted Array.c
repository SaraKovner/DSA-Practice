/*
 * Problem: Given an array of integers nums sorted in non-decreasing order, the task is to find the starting and ending position of a given target value.
 * If the target is not found in the array, return [-1, -1].
 * You must write an algorithm with O(log n) runtime complexity.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים שלמים ממוין בסדר לא-יורד, מצא את המיקום הראשון והאחרון של ערך מטרה נתון
 * 
 * Example:
 * Input: nums = [5, 7, 7, 8, 8, 10], target = 8
 * Output: [3, 4]
 * 
 * Input: nums = [5, 7, 7, 8, 8, 10], target = 6
 * Output: [-1, -1]
 * 
 * Explanation:
 * For the input [5, 7, 7, 8, 8, 10], target = 8, the target 8 is found at positions 3 and 4.
 * For the input [5, 7, 7, 8, 8, 10], target = 6, the target 6 is not found in the array, so the output is [-1, -1].
 * 
 * Time Complexity: O(log n) - שני חיפושים בינאריים
 * Space Complexity: O(1)
 */
//#define ARR_DATA_TYPE int

#include "Question.h"

// פונקציה למציאת האינדקס השמאלי ביותר (הראשון) של מופע מסיום
// חיפוש בינארי למציאת המופע השמאלי ביותר של target
int binarySearchLeft(ARR * arr, int target, int low, int hi)
{
    if(low>hi)
        return -1; // לא נמצא
        
    int mid=(low+hi)/2;
    if(arr->data[mid]==target)
    {
        // אם זה המופע הראשון או שהאלמנט לפניו שונה
        if(mid==0 || arr->data[mid-1]!=target)
            return mid;
        
        // משיך לחפש שמאלה למופע ראשון יותר
        return binarySearchLeft(arr, target, low, mid-1);
    }
    
    if(arr->data[mid]>target)
        return binarySearchLeft(arr, target, low, mid-1);
    
    return binarySearchLeft(arr, target, mid+1, hi);
}

// חיפוש בינארי למציאת המופע הימני ביותר (האחרון) של target
int binarySearchRight(ARR * arr, int target, int low, int hi)
{
    if(low>hi)
        return -1; // לא נמצא
        
    int mid=(low+hi)/2;
    if(arr->data[mid]==target)
    {
        // אם זה המופע האחרון או שהאלמנט אחריו שונה
        if(mid==ARR_TotalSize(arr)-1 || arr->data[mid+1]!=target)
            return mid;
            
        // משיך לחפש ימינה למופע אחרון יותר
        return binarySearchRight(arr, target, mid+1, hi);
    }
    
    if(arr->data[mid]>target)
        return binarySearchRight(arr, target, low, mid-1);
        
    return binarySearchRight(arr, target, mid+1, hi);
}

// פונקציה ראשית למציאת מיקומי התחלה והסיום של target במערך ממוין
ARR  *  find_positions_array(ARR  *  nums, int  target) 
{
    // בדיקת קצה
    if(nums==NULL || nums->data==NULL)
        return nums;
        
    // יצירת מערך תוצאה עם 2 אלמנטים [תחילה, סוף]
    uint64_t d[1]={2};
    ARR* res=ARR_Create(d, 1);
    
    // חיפוש המיקום הראשון של target
    res->data[0]=binarySearchLeft(nums, target, 0, ARR_TotalSize(nums)-1);
    
    // אם target לא נמצא, החזר [-1, -1]
    if(res->data[0]==-1)
        res->data[1]=-1;
    else
        // אחרת חפש את המיקום האחרון
        res->data[1]=binarySearchRight(nums, target, 0, ARR_TotalSize(nums)-1);
    
    return res;  
}
