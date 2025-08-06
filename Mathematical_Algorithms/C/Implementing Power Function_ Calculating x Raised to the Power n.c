/*
 * Problem: Implement the function pow(x, n), which calculates x raised to the power n (i.e., x^n).
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: ממש את הפונקציה pow(x, n), המחשבת x בחזקת n
 * 
 * Example:
 * Input: x = 2.0, n = 10
 * Output: 1024.0
 * 
 * Input: x = 2.1, n = 3
 * Output: 9.261
 * 
 * Input: x = 2.0, n = -2
 * Output: 0.25
 * 
 * Explanation:
 * For the input x = 2.0, n = 10, the result is 2.0^10 = 1024.0.
 * For the input x = 2.1, n = 3, the result is 2.1^3 ≈ 9.261.
 * For the input x = 2.0, n = -2, the result is 2.0^-2 = 1/(2^2) = 0.25.
 * 
 * Time Complexity: O(log n) - אם משתמשים באלגוריתם חזקה מהירה
 * Space Complexity: O(1)
 */
#include "Question.h"

double  power_function(double  x, int  n)  
{
    if(!n)
        return 1;
        
    double res=x;
    for(int i=n-1; i>0; i--)
    {
        // printf("1. %f\t", res);
        res*=x;
    }
        
    for(int i=n; i<=0; i++)
    {
        res/=x;
        // printf("2. %f\t", res);
    }
    return res;  
}
