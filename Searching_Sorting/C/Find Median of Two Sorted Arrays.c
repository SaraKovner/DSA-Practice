/*
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * The overall run time complexity should be O(log (m+n)).
 *  
 * Example 1:
 *     Input: nums1 = [1, 3], nums2 = [2]
 *     Output: 2.00000
 *     Explanation: merged array = [1, 2, 3] and median is 2.
 *  
 * Example 2:
 *     Input: nums1 = [1, 2], nums2 = [3, 4]
 *     Output: 2.50000
 *     Explanation: merged array = [1, 2, 3, 4] and median is (2 + 3) / 2 = 2.5.
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מצא את המדיאן של שני מערכים ממוינים
 * 
 * Time Complexity: O(log(m+n)) - Binary Search
 * Space Complexity: O(log(m+n)) - רקורסיה
 */
#include "Question.h"
#define MIN(a, b)(a>b ? b : a)
// פונקציית עזר למציאת האיבר ה-K הקטן ביותר בשני מערכים ממוינים
int find_K(int * nums1, int len1, int * nums2, int len2, int k)
{
    // נרצה שהמערך הראשון תמיד יהיה קטן יותר
    if(len1>len2)
        return find_K(nums2, len2, nums1, len1, k);
    
    // אם המערך הראשון ריק נחזיר את האיבר K מהמערך השני
    if(len1==0)
        return nums2[k-1];
        
    // אם מחפשים שהאיבר הראשון הוא הכי קטן
    if(k==1)
        return (nums1[0]<nums2[0] ? nums1[0] : nums2[0]);
        
        
    // נחשב איפה נרצה לחתוך את המערכים - Binary Search
    int i=MIN(k/2, len1);
    int j=k-i;  // המשלים לעומת החיתוך שלקחנו במערך הראשון
    
    if(nums1[i-1]<nums2[j-1])
    {
        // זה אומר שהאיברים שמתחת לI במערך הראשון יורדים כי הם יותר קטנים בטוח מהאיבר שמחפשים
        return find_K(nums1+i, len1-i, nums2, len2, k-i);
    }
    
    // ולהפך
    return find_K(nums1, len1, nums2+j, len2-j, k-j);
}


// פונקציה ראשית למציאת מדיאן של שני מערכים ממוינים
// אלגוריתם: Binary Search למציאת האיבר ה-K הקטן ביותר
double find_median(ARR  *  nums1, ARR  *  nums2) 
{
    if(nums1==NULL || nums1->total_size==0)
    {
        if(nums2==NULL || nums2->total_size==0)
            return 0;   // NULL
        return nums2->data[nums2->total_size/2+(!nums2->total_size%2)];
    }
    if(nums2==NULL || nums2->total_size==0)
        return nums1->data[nums1->total_size/2+(!nums1->total_size%2)];
    
    int len1=nums1->total_size, len2=nums2->total_size;
    int total_length=len1+len2;
    
    if(total_length%2==1)
    {
        // אם האורך הכולל הוא אי זוגי אז צריך להחזיר את האיבר האמצעי
        return find_K(nums1->data, len1, nums2->data, len2, total_length/2+1);
    }
    
    // אם האורך הוא זוגי צריך להחזיר את הממוצע בין שני איברים
    int left=find_K(nums1->data, len1, nums2->data, len2, total_length/2);
    int right=find_K(nums1->data, len1, nums2->data, len2, total_length/2+1);
    return (left+right)/2.0;
}
