/*
 * There is an exam room with n seats in a single row labeled from 0 to n - 1.
 * When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. If there are multiple such seats, they sit in the seat with the lowest number. If no one is in the room, then the student sits at seat number 0.
 * Design a class that simulates the mentioned exam room.
 * Implement the ExamRoom class:
 * ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
 * int seat() Returns the label of the seat at which the next student will set.
 * void leave(int p) Indicates that the student sitting at seat p will leave the room. It is guaranteed that there will be a student sitting at seat p.
 * 
 * Example 1:
 * Input
 * ExamRoom examRoom = new ExamRoom(10);
 * examRoom.seat();
 * examRoom.seat();
 * examRoom.seat();
 * examRoom.seat();
 * examRoom.leave(4);
 * examRoom.seat();
 * Output
 * [null, 0, 9, 4, 2, null, 5]
 * 
 * Explanation
 * ExamRoom examRoom = new ExamRoom(10);
 * examRoom.seat(); // return 0, no one is in the room, then the student sits at seat number 0.
 * examRoom.seat(); // return 9, the student sits at the last seat number 9.
 * examRoom.seat(); // return 4, the student sits at the last seat number 4.
 * examRoom.seat(); // return 2, the student sits at the last seat number 2.
 * examRoom.leave(4);
 * examRoom.seat(); // return 5, the student sits at the last seat number 5.
 * 
 * Constraints:
 * 1 <= n <= 10^9
 * It is guaranteed that there is a student sitting at seat p.
 * At most 10^4 calls will be made to seat and leave.
 * 
 * Difficulty: 🟡 Medium
 * 
 * תרגום: עיצוב כיתת בחינה - מקסום מרחק בין תלמידים
 * 
 * Time Complexity: O(log n) for seat and leave operations
 * Space Complexity: O(n) - worst case for storing occupied seats
 */
#include <set>
#include <queue>
using namespace std;

// מחלקת ExamRoom - סימולציה של כיתת בחינה עם מקסום מרחקים
// אלגוריתם: Priority Queue + Set - ניהול טווחים פנויים
class ExamRoom 
{
    private:
        int N; // מספר המושבים הכולל
        set<int> seats; // מכיל את המקומות שתפוסים כרגע
        
        // מבנה של טווח פנוי בין שני מושבים
        struct Interval
        {
            int left, right, N; // גבולות הטווח וגודל האולם
            Interval(int l, int r, int n) : left(l), right(r), N(n) {}
            
            // מחשב את המרחק למושב הטוב ביותר בטווח הזה
            int dist() const
            {
                if(left==-1) return right; // טווח מתחילת האולם
                if(right==N) return N-1-left; // טווח עד סוף האולם
                return (right-left)/2; // טווח באמצע - מרחק לקרוב ביותר
            }
            
            // השוואה הפוכה: טווח עם מרחק גדול קודם. אם זהה - שמאלי יותר קודם
            bool operator<(const Interval&other) const
            {
                int d1=dist(), d2=other.dist();
                if(d1==d2)
                    return left>other.left; // עדיפות לאינדקס נמוך יותר
                return d1<d2; // עדיפות למרחק גדול יותר
            }
        };
        
        priority_queue<Interval> pq; // תור עדיפויות של טווחים פנויים
        
    public:
        // בנאי - אתחול האולם עם n מושבים
        ExamRoom(int n) : N(n)
        {
            // בהתחלה כל האולם פנוי (טווח מ--1 ל-N)
            pq.push(Interval(-1, N, N));
        }
        
        // פונקציית seat - מציאת המושב האופטימלי הבא
        int seat() 
        {
            // נשלוף את הטווח הכי טוב (עם המרחק הגדול ביותר)
            while(!pq.empty())
            {
                auto [l, r, _]=pq.top();
                pq.pop();
                
                // נבדוק שהגבולות עדיין קיימים במערכת (לא הוסרו)
                auto itL = (l==-1) ? seats.begin() : seats.find(l);
                auto itR = (r==N) ? seats.end() : seats.find(r);

                // אם הטווח עדיין תקף
                if((l==-1 || itL!=seats.end()) && (r==N || itR!=seats.end()))
                {
                    // מחשבים את המיקום האופטימלי בטווח
                    int s=(l==-1) ? 0 :        // תחילת האולם
                          (r==N) ? N-1:        // סוף האולם  
                          (l+r)/2;             // אמצע הטווח
                    
                    // מוסיפים את המושב למקומות התפוסים
                    seats.insert(s);
                    
                    // מפרקים את הטווח לשנים ומוסיפים אותם חזרה לתור
                    pq.push(Interval(l, s, N)); // טווח שמאלי
                    pq.push(Interval(s, r, N)); // טווח ימני
                    
                    return s;
                }
            }
            
            return -1; // לא אמור להגיע לכאן
        }
        
        // פונקציית leave - הסרת תלמיד ממושב p
        void leave(int p) 
        {
            auto it = seats.find(p);
            if(it==seats.end())
                return; // המושב לא תפוס
            
            // מחפשים את המושבים הסמוכים (שמאל וימין)
            auto l=(it==seats.begin()) ? -1 : *prev(it);
            auto r=(next(it)==seats.end()) ? N : *next(it);

            // יוצרים טווח חדש שמחבר את הפער שנוצר
            pq.push(Interval(l, r, N));
            seats.erase(it); // מסירים מהמקומות התפוסים
        }
};