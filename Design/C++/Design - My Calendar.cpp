/*
 * You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.
 * A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).
 * The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.
 * Implement the MyCalendar class:
 * MyCalendar() Initializes the calendar object.
 * boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
 * 
 * Example 1:
 * Input
 *  MyCalendar myCalendar = new MyCalendar();
 *  myCalendar.book(10, 20);
 *  myCalendar.book(15, 25);
 *  myCalendar.book(20, 30);
 * Output
 *  [null, true, false, true]
 * 
 * Explanation
 * MyCalendar myCalendar = new MyCalendar();
 * myCalendar.book(10, 20); // return True
 * myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
 * myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
 * 
 * Constraints:
 * 0 <= start < end <= 10^9
 * At most 1000 calls will be made to book.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: עיצוב יומן - מניעת הזמנות כפולות
 * 
 * Time Complexity: O(log n) - פעולות על Set
 * Space Complexity: O(n) - אחסון כל האירועים
 */
using namespace std;
#include <set>
#include <utility>

// מחלקת MyCalendar - ניהול יומן עם מניעת הזמנות כפולות
// אלגוריתם: Set-based interval management - שימוש ב-Set למיון אוטומטי
class MyCalendar {
    private:
        set<pair<int, int>> events; // Set של זוגות (start, end) ממוין אוטומטית
        
    public:
        // בנאי - אתחול יומן ריק
        MyCalendar() 
        {
            // אתחול ריק
        }
        
        // פונקציית book - הוספת אירוע חדש ליומן
        bool book(int startTime, int endTime) 
        {
            // מציאת האירוע הראשון שמתחיל >= startTime
            auto it = events.lower_bound({startTime, endTime});
            
            // בדיקת חפיפה עם האירוע הבא
            if(it != events.end() && it->first < endTime)
                return false; // יש חפיפה: האירוע הבא מתחיל לפני שהנוכחי נגמר
                
            // בדיקת חפיפה עם האירוע הקודם
            if(it != events.begin())
            {
                it--; // מעבר לאירוע הקודם
                if(it->second > startTime)
                    return false; // יש חפיפה: האירוע הקודם נגמר אחרי שהנוכחי מתחיל
            }
            
            // אין חפיפות - הוספת האירוע ליומן
            events.insert({startTime, endTime});
            return true;
        }
};