/*
 * Problem Description:
 * Given an absolute path for a Unix-style file system, which begins with a slash '/', transform this path into its simplified canonical path.
 * In Unix-style file system context, a single period '.' signifies the current directory, a double period '..' denotes moving up one directory level, and multiple slashes such as '//' are interpreted as a single slash. In this problem, treat sequences of periods not covered by the previous rules (like '...') as valid names for files or directories.
 * The simplified canonical path should adhere to the following rules:
 * It must start with a single slash '/'.
 * Directories within the path should be separated by only one slash '/'.
 * It should not end with a slash '/', unless it's the root directory.
 * It should exclude any single or double periods used to denote current or parent directories.
 * Return the new path.
 * 
 * Example:
 * 
 *     Input: path = "/home/"
 *     Output: "/home"
 * 
 *     Input: path = "/../"
 *     Output: "/"
 * 
 *     Input: path = "/home//foo/"
 *     Output: "/home/foo"
 * 
 * Input: path = "/a/./b/../../c/"
 * Output: "/c"
 * 
 * Explanation:
 * For the input "/home/", the simplified path is "/home".
 * For the input "/../", the simplified path is "/", as moving up from the root directory remains at the root.
 * For the input "/home//foo/", the simplified path is "/home/foo", where double slashes are interpreted as a single slash.
 * For the input "/a/./b/../../c/", the simplified path is "/c", where . refers to the current directory and .. moves up one directory level.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: פישוט נתיב מערכת קבצים בסגנון Unix - המרת נתיב לצורה קנונית מפושטת
 * 
 * Time Complexity: O(n) - מעבר יחיד על המחרוזת
 * Space Complexity: O(n) - אחסון הנתיב המפושט
 */
#include "Question.hpp"
#include "Utils.hpp"
#include <string>
using namespace std;

// פונקציה ראשית לפישוט נתיב מערכת קבצים Unix
// אלגוריתם: עיבוד מחרוזת עם טיפול במקרים מיוחדים
string simplify_path(string path)
{
    string newPath = ""; // הנתיב המפושט שנבנה
    
    int count_sl = 0; // מונה סלאשים רצופים
    int index = 0;    // אינדקס עזר
    
    // מעבר על כל תו בנתיב המקורי
    for(int i = 0; i < path.length(); i++)
    {
        switch(path[i])
        {
            case '/' :  // טיפול בסלאשים - מניעת כפילויות
                        if(count_sl == 0) 
                        { 
                           newPath += '/'; // רק סלאש ראשון מרצף סלאשים
                        } 
                       count_sl++; // ספירת סלאשים רצופים
                       break;
                       
            case '.' :  // טיפול בנקודות - '.', '..', '...' וכו'
                        if(i+1 < path.length() && path[i+1] == '.')
                        {
                            // בדיקה אם יש שלוש נקודות או יותר (שם תיקייה חוקי)
                            if(i+2 < path.length() && path[i+1] == '.' && path[i+2] == '.')
                            {
                                // מצב של שלוש נקודות או יותר - זה שם תיקייה חוקי
                                int nextSlash = path.find('/', i);
                                if (nextSlash == string::npos)      // אם אין סלאש בא - עד סוף המחרוזת
                                    nextSlash = path.length();
                                string dir = path.substr(i, nextSlash - i);  // חילוץ שם התיקייה
                                newPath += dir;                              // הוספת שם התיקייה לנתיב
                                i = nextSlash - 1;                           // קידום האינדקס
                                count_sl = 0;  // איפוס מונה הסלאשים
                            }
                            else // מצב של '..' - עלייה לתיקייה האב
                            {
                                if(newPath.length() > 1)  // אם לא בשורש - עלייה לתיקייה האב
                                {
                                    int lastSlash = newPath.find_last_of('/', newPath.length() - 2);
                                    newPath.erase(lastSlash + 1);  // מחיקת התיקייה הנוכחית
                                }
                                count_sl = 0; // איפוס מונה הסלאשים
                            }
                        }
                        else // מצב של '.' - תיקייה נוכחית (לא עושים כלום)
                        {
                            count_sl++; // ספירת סלאשים לפני הנקודה
                        }
                        break;
                        
            default  : // כל תו אחר - חלק משם תיקייה או קובץ
            {
                // חיפוש הסלאש הבא לחילוץ שם התיקייה המלא
                int nextSlash = path.find('/', i);
                if (nextSlash == string::npos)      // אם אין סלאש בא - עד סוף המחרוזת
                    nextSlash = path.length();
                string dir = path.substr(i, nextSlash - i);  // חילוץ שם התיקייה המלא
                newPath += dir;                              // הוספת שם התיקייה לנתיב המפושט
                i = nextSlash - 1;                           // קידום האינדקס לסלאש הבא
                count_sl = 0;  // איפוס מונה הסלאשים
                break;
            }
        }
    }
    
    // הסרת סלאש סופי אם זה לא שורש המערכת
    if(newPath.length() > 1 && newPath.back() == '/')
        newPath.pop_back();
        
    return newPath; // החזרת הנתיב המפושט
}