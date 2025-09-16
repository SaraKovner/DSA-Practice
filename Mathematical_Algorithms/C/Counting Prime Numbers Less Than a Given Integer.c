/*
 * Description:
 * Given an integer n, return the number of prime numbers that are strictly less than n.
 * 
 * Example 1:
 * Input: n = 10
 * Output: 4
 * Explanation: The prime numbers less than 10 are 2, 3, 5, and 7. There are 4 prime numbers less than 10.
 * 
 * Example 2:
 * Input: n = 0
 * Output: 0
 * Explanation: There are no prime numbers less than 0.
 * 
 * Example 3:
 * Input: n = 1
 * Output: 0
 * Explanation: There are no prime numbers less than 1.
 * 
 * Constraints:
 * 0 <= n <= 5 * 10^6
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: ספירת מספר המספרים הראשוניים הקטנים ממספר נתון
 * 
 * Time Complexity: O(n * sqrt(n)) - לכל מספר עד n בודקים ראשוניות עד השורש
 * Space Complexity: O(1) - משתמשים במשתנים קבועים בלבד
 */
#include "Question.h"
#include <math.h>

// פונקציית עזר לבדיקה האם מספר הוא ראשוני
// אלגוריתם: Trial Division - בדיקת חלוקה עד השורש
int is_prime(int num)
{
    // מספרים קטנים מ-2 אינם ראשוניים
    if(num < 2)
        return 0;
        
    // בדיקת חלוקה עד השורש של המספר
    int sq = sqrt(num);
    for(int i = 2; i <= sq; i++)
        if(num % i == 0) // אם נמצא מחלק - המספר אינו ראשוני
            return 0;
            
    return 1; // המספר ראשוני
}

// פונקציה ראשית לספירת מספר המספרים הראשוניים הקטנים מ-n
// אלגוריתם: Brute Force - בדיקת כל מספר עד n
int primes_less_than_integer(int n) 
{
    int count = 0; // מונה המספרים הראשוניים

    // מעבר על כל המספרים מ-1 עד n-1
    for(int i = 1; i < n; i++)
        count += is_prime(i); // הוספה למונה אם המספר ראשוני
    
    return count;
}

/*
 * הערה: פתרון יעיל יותר - Sieve of Eratosthenes
 * 
 * הפתרון הנוכחי משתמש ב-Trial Division עם סיבכיות O(n * sqrt(n)).
 * עבור ערכים גדולים של n (עד 5*10^6), פתרון יעיל יותר הוא Sieve of Eratosthenes:
 * 
 * Time Complexity: O(n log log n) - פי 30 יותר מהיר!
 * Space Complexity: O(n) - דורש מערך נוסף
 * 
 * הרעיון: במקום לבדוק כל מספר בנפרד, מסמנים מראש את כל הלא-ראשוניים:
 * 1. יוצרים מערך boolean בגודל n (הכל true)
 * 2. עבור כל ראשוני i, מסמנים את כל הכפולות שלו כ-false
 * 3. סופרים כמה true נשארו
 * 
 * int countPrimes_Sieve(int n) {
 *     if (n <= 2) return 0;
 *     
 *     bool* isPrime = (bool*)malloc(n * sizeof(bool));
 *     memset(isPrime, true, n * sizeof(bool));
 *     isPrime[0] = isPrime[1] = false;
 *     
 *     for (int i = 2; i * i < n; i++) {
 *         if (isPrime[i]) {
 *             for (int j = i * i; j < n; j += i) {
 *                 isPrime[j] = false;
 *             }
 *         }
 *     }
 *     
 *     int count = 0;
 *     for (int i = 2; i < n; i++) {
 *         if (isPrime[i]) count++;
 *     }
 *     
 *     free(isPrime);
 *     return count;
 * }
 * 
 * למה זה יעיל יותר?
 * - כל מספר מסומן רק פעם אחת (על ידי המחלק הראשוני הקטן ביותר)
 * - פחות פעולות כפל/חלוקה, יותר פעולות חיבור פשוטות
 * - לא בודקים חלוקה - רק מסמנים במערך
 * - עבור n=1,000,000: Trial Division ~500M פעולות, Sieve ~15M פעולות
 */