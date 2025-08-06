/*
 * Problem: Given a signed 32-bit integer x, return the integer obtained by reversing its digits. If reversing x causes the value to go outside the 32-bit integer range [-2^31, 2^31 - 1], then return 0.
 * Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: נתון מספר שלם עם סימן 32-ביט, החזר את המספר עם ספרות הפוכות
 * 
 * Examples:
 * Example 1:
 * Input: x = 123
 * Output: 321
 * 
 * Example 2:
 * Input: x = -123
 * Output: -321
 * 
 * Example 3:
 * Input: x = 120
 * Output: 21
 * 
 * Constraints:
 * -2^31 <= x <= 2^31 - 1
 * 
 * Time Complexity: O(log x)
 * Space Complexity: O(1)
 */
#include "Question.h"
#include <math.h>

int  reverse_integer_digits(int  x)  {
    int num=0, isNeg=0;
    
    int max=2147483641, temp;
    
    //זה המספר בכי גדול שניתן להפוך ולא תהיה גלישה
    // if(num>2147483641 && )
    //     return 0;
    
    if(x<0)
    {
        x=x*-1;
        isNeg=1;
    }
    
    temp=x;
    if(x>=pow(10, 9))
    {
        while(temp>0)
        {
            if(temp%10>max%10)
                return 0;
            max/=10;
            temp/=10;
        }
    }
    
    while(x>0)
    {
        num*=10;
        num+=x%10;
        x/=10;
    }
    
    if(isNeg)
        num*=-1;
    
    return num;  
}
