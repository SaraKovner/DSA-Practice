/*
 * Problem: There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
 * Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
 * Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
 * You must decrease the overall operation steps as much as possible.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מערך מספרים שלמים ממוין בסדר לא-יורד, שסובב בנקודת ציר לא ידועה. מצא אם target קיים במערך
 * 
 * Example:
 * Input: nums = [4,5,6,6,7,0,1,2,4,4], target = 0
 * Output: true
 * 
 * Input: nums = [4,5,6,6,7,0,1,2,4,4], target = 3
 * Output: false
 * 
 * Explanation:
 * For the input nums = [4,5,6,6,7,0,1,2,4,4], target = 0, the target 0 is found in the array.
 * For the input nums = [4,5,6,6,7,0,1,2,4,4], target = 3, the target 3 is not found in the array.
 * 
 * Time Complexity: O(log n) average, O(n) worst case
 * Space Complexity: O(1)
 */
// #define ARR_DATA_TYPE int
#include "Question.h"

int find_k(ARR  *  nums, int low, int hi)
{
    if(low==hi)
        return hi;
    // if(hi>low)
    //     return -1;
    
    int mid=(low+hi)/2;
    // if(mid==0 || mid==nums->total_size-1 || nums->data[mid]<nums->data[mid-1])
    //     return mid;
        
    // if(nums->data[low]<nums->data[mid] && nums->data[mid]<nums->data[hi])
    //     return hi+1==nums->total_size ? 0 : low;
        
    if(nums->data[hi]<nums->data[mid])
        return find_k(nums, mid+1, hi);
        
    return find_k(nums, low, mid);
}

int binerySerch(ARR *  nums, int low, int hi, int target)
{
    if(hi<low)
        return -1;
    
    int mid=(low+hi)/2;
    if(nums->data[mid]==target)
        return mid;
    
    if(nums->data[mid]<target)
        return binerySerch(nums, mid+1, hi, target);
        
    return binerySerch(nums, low, mid-1, target);
}

STR  search_target_in_array(ARR  *  nums, int  target)  {
    if(nums==NULL || nums->total_size==0)
        return STR_Copy_raw("false");
    
    // printf("a");
    
    int k=find_k(nums, 0, nums->total_size-1);
    
    printf("%d\t", k);
    
    if(target<nums->data[0])
        k=binerySerch(nums, k, nums->total_size-1, target);
    else
        k=binerySerch(nums, 0, k, target);
    
    printf("%d\t", k);
    
    return k==-1 ? STR_Copy_raw("false") :  STR_Copy_raw("true");
}
