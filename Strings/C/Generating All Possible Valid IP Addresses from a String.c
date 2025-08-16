/*
 * Problem Description:
 * A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
 * For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
 * Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
 *  Example:
 *  
 *     Input: s = "25525511135"
 *     Output: {"255.255.11.135", "255.255.111.35"}
 *  
 *     Input: s = "0000"
 *     Output: {"0.0.0.0"}
 *  
 * Explanation:
 * For the input s = "25525511135", the valid IP addresses are {"255.255.11.135", "255.255.111.35"}.
 * For the input s = "0000", the valid IP address is {"0.0.0.0"}.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: יצירת כל כתובות IP התקינות האפשריות ממחרוזת ספרות
 * 
 * Time Complexity: O(1) - מספר קבוע של אפשרויות (3^4)
 * Space Complexity: O(1) - מספר קבוע של תוצאות
 */
#include "Question.h"
#include <string.h>
#include <ctype.h>

// פונקציית עזר - בודקת אם האוקטט תקין
int valid_octet(const char* s, int len)
{
    if(len==0 || len>3)
        return 0;   // גודל לא תקין
    
    if(s[0]=='0' && len>1)
        return 0;   // כי יש 0 בראש מספר והוא לא בודד
    
    // חישוב המספר שנשלח במחרוזת
    int val=0;
    for(int i=0; i<len; i++)
        val=val*10+(s[i]-'0');
        
    return val<=255; // בדיקה שהמספר בטווח 0-255
}

// פונקציה ראשית ליצירת כל כתובות IP התקינות האפשריות
// אלגוריתם: שלוש לולאות מקוננות לחלוקת 4 חלקים
Set*  get_all_valid_ip(STR  s) 
{
	int n=strlen(s);
	
	// הקטנת המחרוזת בגלל הסוגרים
	for(int i=0; i<n && !isdigit(s[i]); i++)
	{
	    s++;    // קידום המצביע
	    n--; // הקטנת אורך המחרוזת
	}
	s++;
	for(int i=n-1; i>=0 && !isdigit(s[i]); i--)
	{
        n--;
	}
    s[n]='\0';

	
	if(n<4 || n>12)
	    return Set_Create(0);
	    
	Set* ips=Set_Create(64); // הגודל המקסימלי
	
	// הלולאה הראשונה בוחרת את החלק הראשון שאורכו בין 1 ל3 תווים
	for(int i=0; i<=3 && i<n-2; i++)
	{
	    if(!valid_octet(s, i))
	        continue; // כלומר הבחירה הזו לא חוקית
	     
	   // הלולאה בוחרת איפה לסיים את האוקטט השני   
	   for(int j=i+1; j<=i+3 && j<n-1; j++)
	   {
	        if(!valid_octet(s+i, j-i))
                continue; // כלומר הבחירה הזו לא חוקית עבור האוקטט השני
                
            // הלולאה השלישית בוחרת איפה לסיים את האוקטט השלישי
            for(int k=j+1; k<=j+3 && k<n; k++)
            {
                int len4=n-k; // אורך האוקטט הרביעי
                if(!valid_octet(s+j, k-j))
                    continue;
                if(!valid_octet(s+k, len4))
                    continue;
                    
                // אם הבדיקות עברו עד פה זה אומר שיש יצוג תקין לפי החלוקה הזו
                char buf[16];   // הגודל המקסימלי לכתובת כולל תו הסיום
                
                // פונקציה שמעתיקה תוכן למחרוזת לפי פורמט מסוים
                snprintf(buf, sizeof(buf), "%.*s.%.*s.%.*s.%s", // הפורמט בו תיכתב המחרוזת
                    i, s,       // החלק הראשון מתחיל בתחילת המחרוזת ואורכו i
                    j-i, s+i,   // החלק השני מתחיל אחרי החלק הראשון
                    k-j, s+j, 
                    s+k);   // מתחיל כאן ומסתיים בסוף המחרוזת
                
                STR ip=STR_Copy(buf);
                Set_Add(ips, ip);
            }
	        
	   }
	}
	
	return ips;
}
