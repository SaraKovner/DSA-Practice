/*
 * Description: Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 *  
 * Example 1:
 * Input: nums = [1, 2, 3, 4]
 * Output: [24, 12, 8, 6]
 *  
 * Example 2:
 * Input: nums = [-1, 1, 0, -3, 3]
 * Output: [0, 0, 9, 0, 0]
 *  
 * Constraints:
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים, החזר מערך שכל אלמנט בו הוא מכפלת כל האלמנטים חוץ מהאלמנט הנוכחי
 * 
 * Time Complexity: O(n) - שני מעברים על המערך
 * Space Complexity: O(n) - שני מערכי עזר
 */
#include "Question.h"

// פונקציה ראשית לחישוב מכפלת כל האלמנטים חוץ מהאלמנט הנוכחי
// אלגוריתם: שני מעברים - מכפלות שמאליות וימניות
ARR  *  product_of_array(ARR  *  nums)  
{
    int len=nums->dimensions[0]; // אורך המערך
    
    // יצירת שני מערכי עזר
    int* arr_left=(int*)malloc(sizeof(int)*len);  // מכפלות משמאל
    int* arr_right=(int*)malloc(sizeof(int)*len); // מכפלות מימין
    
    // יצירת מערך תוצאה
    uint64_t d[1]={len};
    ARR* res=ARR_Create(d, 1);
    
    // אתחול מקרי הבסיס
    arr_left[0]=1;      // לפני האלמנט הראשון אין כלום
    arr_right[len-1]=1; // אחרי האלמנט האחרון אין כלום
    
    // מעבר אחד: חישוב מכפלות שמאליות וימניות באן
    for(int i=1; i<len; i++)
    {
        // חישוב כל הכפולות מצד שמאל של האיבר הנוכחי ובמערך השני מצד ימין של האיבר
        arr_left[i]=arr_left[i-1]*nums->data[i-1];           // מכפלת כל האלמנטים שמאלה ל-i
        arr_right[len-1-i]=arr_right[len-i]*nums->data[len-i]; // מכפלת כל האלמנטים ימינה ל-(len-1-i)
    }

    // מעבר שני: חישוב התוצאה הסופית
    for(int i=0; i<len; i++)
        res->data[i]=arr_left[i]*arr_right[i]; // מכפלת השמאל בימין
    
    // שחרור זיכרון
    free(arr_left);
    free(arr_right);
    
    return res; 
}
