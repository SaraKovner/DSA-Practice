/*
 * Problem Description:
 * Given an integer array nums, the task is to find all unique triplets [nums[i], nums[j], nums[k]] such that the following conditions are met:
 * i ≠ j
 * i ≠ k
 * j ≠ k
 * nums[i] + nums[j] + nums[k] = 0
 * The solution set must not contain duplicate triplets.
 *  
 * Example:
 * Input: nums = [-1, 0, 1, 2, -1, -4]
 * Output: [[-1, -1, 2], [-1, 0, 1]]
 * Explanation:
 * In the example above, the unique triplets that sum to zero are:
 * [-1, -1, 2]
 * [-1, 0, 1]
 * These triplets meet the criteria, and there are no duplicate triplets in the solution set.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים שלמים, מצא את כל השלישיות הייחודיות שסכומן 0
 * 
 * Time Complexity: O(n²) - מיון + Two Pointers
 * Space Complexity: O(1) - ללא פלט
 */
//#define ARR_DATA_TYPE int

#include "Question.h"

// פונקציית השוואה ל-qsort - מיון עולה
int cmp(const void* a, const void* b)
{
    int a_int = *(const int*)a;
    int b_int = *(const int*)b;
    return a_int - b_int;
}

// פונקציית עזר להוספת שלישיה למערך התוצאות
void add_triplet(ARR* res, int a, int b, int c)
{
    res->data = (ARR_DATA_TYPE*)realloc(res->data, (res->total_size + 3) * sizeof(ARR_DATA_TYPE));
    res->data[res->total_size] = a;
    res->data[res->total_size + 1] = b;
    res->data[res->total_size + 2] = c;
    res->total_size += 3;
    res->dimensions[0]++;
}

// פונקציה ראשית למציאת כל השלישיות הייחודיות עם סכום 0 - אלגוריתם Two Pointers
ARR  *  find_uniqe_triplets(ARR  *  nums) 
{
    // בדיקות קצה
    if(nums==NULL || nums->data==NULL || nums->total_size<3)
        return NULL;
        
    int n = nums->total_size;
    
    // מיון המערך בסדר עולה - חיוני לאלגוריתם Two Pointers
    qsort(nums->data, n, sizeof(ARR_DATA_TYPE), cmp);
    
    // יצירת מערך תוצאה
    uint64_t d[2]={0, 3};
    ARR* res = ARR_Create(d, 2);
    
    // לולאה ראשית: בחירת האלמנט הראשון בשלישיה
    for(int i = 0; i < n - 2; i++)
    {
        // דילוג על כפילות באלמנט הראשון
        if(i > 0 && nums->data[i] == nums->data[i-1])
            continue;
            
        int left = i + 1;    // מצביע שמאל
        int right = n - 1;   // מצביע ימין
        
        // אלגוריתם Two Pointers
        while(left < right)
        {
            int sum = nums->data[i] + nums->data[left] + nums->data[right];
            
            if(sum == 0)
            {
                // מצאנו שלישיה תקינה!
                add_triplet(res, nums->data[i], nums->data[left], nums->data[right]);
                
                // דילוג על כפילות במצביע השמאלי
                while(left < right && nums->data[left] == nums->data[left + 1])
                    left++;
                // דילוג על כפילות במצביע הימני
                while(left < right && nums->data[right] == nums->data[right - 1])
                    right--;
                    
                left++;
                right--;
            }
            else if(sum < 0)
            {
                // הסכום קטן מדי - צריך להגדיל אותו
                left++;
            }
            else
            {
                // הסכום גדול מדי - צריך להקטין אותו
                right--;
            }
        }
    }
    
    return res;
}
