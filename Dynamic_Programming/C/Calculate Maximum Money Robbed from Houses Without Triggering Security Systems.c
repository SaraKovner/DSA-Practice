/*
 * Description: As a professional robber, you are planning to rob houses along a street. Each house has a certain amount of money stashed. The constraint is that robbing two adjacent houses on the same night will trigger security systems that alert the police. Given an integer array nums representing the amount of money in each house, determine the maximum amount of money you can rob tonight without alerting the police.
 * 
 * Example 1:
 * 
 * Input: nums = [1, 2, 3, 1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3). Total amount = 1 + 3 = 4.
 *  
 * 
 * Example 2:
 * 
 * Input: nums = [2, 7, 9, 3, 1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9), and rob house 5 (money = 1). Total amount = 2 + 9 + 1 = 12.
 *  
 * 
 * The task is to create a function that can efficiently compute the maximum amount of money that can be robbed without triggering the security systems.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: כשודד מקצועי, אתה מתכנן לשדוד בתים ברחוב. לא ניתן לשדוד שני בתים סמוכים. מצא את הסכום המקסימלי שניתן לשדוד
 * 
 * Time Complexity: O(n) - תכנות דינמי
 * Space Complexity: O(n) - מערך DP
 */
//#define ARR_DATA_TYPE int

#include "Question.h"
#define MAX(a, b) ((a)>(b) ? (a) : (b))

// פונקציה ראשית לחישוב הסכום המקסימלי שניתן לשדוד מבתים
// אלגוריתם: תכנות דינמי - לכל בית בוחרים בין לשדוד אותו או לא
int  max_money_robbed(ARR  *  nums) 
{
    // בדיקות קצה
    if(nums==NULL || nums->data==NULL)
        return 0;
    
    int len=nums->total_size;
    if(len==1)
        return nums->data[0]; // בית אחד - שודדים אותו
        
    // יצירת מערך DP: res[i] = מקסימום כסף עד בית i
    int *res=(int*)malloc(sizeof(int)*len);
    
    // אתחול מקרי הבסיס
    res[0]=nums->data[0]; // בית ראשון - שודדים אותו
    res[1]=MAX(res[0], nums->data[1]); // בית שני - בוחרים את הטוב יותר

    // נוסחת DP: לכל בית i, בוחרים בין:
    // 1. לא לשדוד אותו (res[i-1])
    // 2. לשדוד אותו + המקסימום עד בית i-2 (nums[i] + res[i-2])
    for(int i=2; i<len; i++)
        res[i]=MAX(res[i-1], nums->data[i]+res[i-2]);
    
    // התוצאה היא המקסימום עד הבית האחרון
    int max_sum=res[len-1];
    free(res); // שחרור זיכרון
    return max_sum;  
}
