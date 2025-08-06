/*
 * Problem: Given two integers dividend and divisor, the task is to divide the two integers without using multiplication, division, or the mod operator.
 * The result of the integer division should truncate towards zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
 * Return the quotient after dividing dividend by divisor.
 * Note: Assume the environment can only store integers within the 32-bit signed integer range: [-2^31, 2^31 - 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתונים שני מספרים שלמים dividend ו-divisor, חלק אותם בלי להשתמש בכפל, חילוק או מודולו
 * 
 * Example:
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Explanation:
 * In the first example, 10 divided by 3 is 3.333, which truncates to 3.
 * In the second example, 7 divided by -3 is -2.333, which truncates to -2.
 * 
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
#include "Question.h"
#include <math.h>

int  devision_without_multiplication(int dividend, int divisor)
{
    // if(divisor==0)
    //     return NULL;
        
    int count=0, isNeg=0, d;
    if(dividend<0)
    {
        if(dividend==pow(-2, 31))
            dividend=pow(2, 31)-1;
        else
            dividend*=-1;
        
        isNeg=1;
    }
    if(divisor<0)
    {
        if(divisor==pow(-2, 31))
            divisor=pow(2, 31)-1;
        else
            divisor*=-1;
        
        //כדי לשים את ההפוך של דגל, כי אם שני המספרים שללים אז התוצאה חיובית
        isNeg=abs(1-isNeg);
    }
    
    if(divisor==1)
        return dividend*(isNeg? -1 : 1);
    
    // printf("%d  %d\n", divisor, dividend);

    d=divisor;
    while(d<=dividend)
    {
        d+=divisor;
        count++;
        // printf("%d  %d\n", d, count);
    }
    
    if(isNeg)
        count*=-1;
    
    return count;  // Default return value for non-void function
}
