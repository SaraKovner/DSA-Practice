/*
 * Given a data stream input of non-negative integers a1, a2, ..., an, summarize the numbers seen so far as a list of disjoint intervals.
 * Implement the SummaryRanges class:
 * SummaryRanges() Initializes the object with an empty stream.
 * void addNum(int value) Adds the integer value to the stream.
 * int[][] getIntervals() Returns a summary of the integers in the stream currently as a list of disjoint intervals [starti, endi]. The answer should be sorted by starti.
 * 
 * Example 1:
 * Input
 * SummaryRanges summaryRanges = new SummaryRanges();
 * summaryRanges.addNum(1);     
 * summaryRanges.getIntervals();
 * summaryRanges.addNum(3);     
 * summaryRanges.getIntervals();
 * summaryRanges.addNum(7);     
 * summaryRanges.getIntervals();
 * summaryRanges.addNum(2);     
 * summaryRanges.getIntervals();
 * summaryRanges.addNum(6);     
 * summaryRanges.getIntervals();
 * Output
 * [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7, 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
 * 
 * Explanation
 * SummaryRanges summaryRanges = new SummaryRanges();
 * summaryRanges.addNum(1);      // arr = [1]
 * summaryRanges.getIntervals(); // return [[1, 1]]
 * summaryRanges.addNum(3);      // arr = [1, 3]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
 * summaryRanges.addNum(7);      // arr = [1, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
 * summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
 * summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
 * 
 * Constraints:
 * 0 <= value <= 10^4
 * At most 3 * 10^4 calls will be made to addNum and getIntervals.
 * At most 10^2 calls will be made to getIntervals.
 * 
 * Follow up: What if there are lots of merges and the number of disjoint intervals is small compared to the size of the data stream?
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: זרם נתונים כטווחים נפרדים - סיכום מספרים לטווחים רציפים
 * 
 * Time Complexity: O(log n) for addNum, O(n) for getIntervals
 * Space Complexity: O(n) - worst case for storing all intervals
 */
using namespace std;
#include <map>
#include <vector>

// מחלקת SummaryRanges - ניהול זרם נתונים כטווחים נפרדים
// אלגוריתם: Map-based interval merging - מיזוג טווחים אוטומטי
class SummaryRanges 
{
    private:
        map<int, int> intervals; // מיפוי: start -> end של כל טווח
        
    public:
        // בנאי - אתחול עם זרם ריק
        SummaryRanges() 
        {
            // אתחול ריק
        }
        
        // פונקציית addNum - הוספת מספר חדש לזרם
        void addNum(int value) 
        {
            // אם המספר כבר קיים - אין מה לעשות
            if(intervals.find(value)!=intervals.end())
                return;
            
            // הוספת הערך כטווח חדש [value, value]
            intervals[value]=value;
            auto it=intervals.find(value);
            
            // בדיקת מיזוג עם הטווח הקודם
            if(it!=intervals.begin())
            {
                auto prev_it=prev(it);
                // אם הטווח הקודם נוגע או חופף (end >= value-1)
                if(prev_it->second>=value-1)
                {
                    // מיזוג: הרחבת הטווח הקודם
                    prev_it->second=max(prev_it->second, value);
                    intervals.erase(it); // הסרת הטווח החדש
                    it=prev_it; // עדכון המצביע
                }
            }
            
            // בדיקת מיזוג עם הטווח הבא
            auto next_it=next(it);
            if(next_it!=intervals.end() && next_it->first<=it->second+1)
            {
                // מיזוג: הרחבת הטווח הנוכחי
                it->second=max(next_it->second, it->second);
                intervals.erase(next_it); // הסרת הטווח הבא
            }
        }
        
        // פונקציית getIntervals - החזרת כל הטווחים הנפרדים
        vector<vector<int>> getIntervals() 
        {
            vector<vector<int>> res;
            
            // המרת המפה לוקטור של זוגות [start, end]
            for(const auto& [start, end] : intervals)
                res.push_back({start, end});
                
            return res; // הטווחים כבר ממוינים (תכונה של map)
        }
};