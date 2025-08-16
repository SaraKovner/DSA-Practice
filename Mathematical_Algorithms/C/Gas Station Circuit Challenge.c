/*
 * Problem Description:
 * You are tasked with finding the starting gas station's index on a circular route from which you can successfully drive around the circuit once, clockwise. Each station has a specific amount of gas, and it costs a certain amount of gas to travel to the next station. Your car starts with an empty tank.
 * 
 * Given two integer arrays, gas and cost, determine the index of the starting gas station that allows you to complete the circuit, or return -1 if it's not possible. The solution is guaranteed to be unique if it exists.
 * 
 *  
 * Example:
 *  
 * 
 *     Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * 
 *     Output: 3
 * 
 * Explanation: Start at station 3 where you gain 4 units of gas and spend 1 to reach station 4. Continue this way to successfully complete the circuit.
 * 
 *  
 * 
 *     Input: gas = [2,3,4], cost = [3,4,3]
 * 
 *     Output: -1
 * 
 * Explanation: It's not possible to start at any station and complete the circuit once as the cost exceeds or matches the gas available at each station.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: מצא תחנת דלק התחלה להשלמת מעגל נסיעה
 * 
 * Time Complexity: O(n) - מעבר אחד על המערך
 * Space Complexity: O(1)
 */
#include "Question.h"

// פונקציה ראשית למציאת תחנת דלק התחלה להשלמת מעגל
// אלגוריתם: Greedy - מעבר אחד עם איפוס נקודת התחלה
int  gas_station(ARR  *  gas, ARR  *  cost)  {
    if(gas==NULL || cost==NULL || gas->total_size!=cost->total_size)
        return -1;
    
    int start_index=0;
    int curr_tank=0;   // דלק נוכחי במכל
    int total_tank=0;  // סך כל הדלק במעגל
    int n=gas->total_size;
    
    // אלגוריתם Greedy: מעבר אחד למציאת נקודת התחלה
    for(int i=0; i<n; i++)
    {
        // סכימת הדלק בכללי כדי לדעת האם יש אפשרות בכללי להגיע בלי להתקע בלי דלק
        total_tank+=gas->data[i]-cost->data[i];  // רווח נטו בתחנה i
        curr_tank+=gas->data[i]-cost->data[i];   // דלק נוכחי במכל

        // אם נגמר הדלק, נתחיל מהתחנה הבאה
        if(curr_tank<0)
        {
            start_index=i+1;  // נקודת התחלה חדשה
            curr_tank=0;      // איפוס הדלק
        }
    }
    
    if(total_tank<0)    // זה אומר שאין אפשרות להשלים סיבוב כי מתישהו יהיה חסר דלק
        return -1;
    
    return start_index;  // נקודת התחלה האופטימלית  
}
