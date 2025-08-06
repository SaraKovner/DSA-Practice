/*
 * Problem: A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 * For example, for arr = [1, 2, 3], the following are all the permutations of arr:
 * [1, 2, 3]
 * [1, 3, 2]
 * [2, 1, 3]
 * [2, 3, 1]
 * [3, 1, 2]
 * [3, 2, 1]
 * The next permutation of an array of integers is the next lexicographically greater permutation of its integers. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such an arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: פרמוטציה של מערך היא סידור של איבריו. מצא את הפרמוטציה הלקסיקוגרפית הבאה
 * 
 * Example:
 * Input: nums = [1, 2, 3]
 * Output: [1, 3, 2]
 * 
 * Input: nums = [3, 2, 1]
 * Output: [1, 2, 3]
 * 
 * Explanation:
 * For the input [1, 2, 3], the next permutation is [1, 3, 2].
 * For the input [3, 2, 1], since there is no lexicographical greater permutation, the output is [1, 2, 3].
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
// #define ARR_DATA_TYPE int
#include "Question.h"

// פונקציית השוואה ל-qsort - מיון עולה
int cmp(const void* a, const void* b)
{
    int a_int=*(const int*)a;
    int b_int=*(const int*)b;
    return a_int<b_int? -1 : a_int>b_int? 1:0;
}

// פונקציה למציאת הפרמוטציה הלקסיקוגרפית הבאה
// אלגוריתם Next Permutation - מוצא את הסידור הבא בסדר לקסיקוגרפי
ARR  *  find_next_lexicographical_permutation(ARR  *  nums)  
{
    uint64_t d[1]={nums->total_size};
    ARR*  res=ARR_Create(d, 1); // יצירת מערך תוצאה
    
    int i, pivot=-1; // pivot - מיקום החלפה
    
    // העתקת המערך המקורי
    for(i=res->total_size-1; i>=0; i--)
        res->data[i]=nums->data[i];
        
    // שלב 1: מציאת הpivot - המיקום הימני ביותר שבו יש עלייה
    for(i=res->total_size-1; i>0; i--)
        if(res->data[i]>res->data[i-1]) // מציאת עלייה מימין לשמאל
        {
            pivot=i-1; // המיקום שצריך להחליף
            break;
        }
    
    // אם לא נמצא pivot - המערך בסדר יורד, זו הפרמוטציה האחרונה
    if(pivot==-1)
    {
        qsort(res->data, nums->total_size, sizeof(int), cmp); // חזרה לראשונה
        return res;
    }
    
    // שלב 2: מציאת המספר הקטן ביותר הגדול מ-pivot
    int Imin=pivot+1;
    for(int j=pivot+2; j<res->total_size; j++)
        if(res->data[Imin]>res->data[j] && res->data[j]>res->data[pivot])
            Imin=j;
    
    // שלב 3: החלפת pivot עם המספר שנמצא
    int temp=res->data[pivot];
    res->data[pivot]=res->data[Imin];
    res->data[Imin]=temp;
    
    // שלב 4: מיון החלק שאחרי pivot
    qsort(res->data+pivot+1, nums->total_size-pivot-1, sizeof(int), cmp);
    return res;  
}
