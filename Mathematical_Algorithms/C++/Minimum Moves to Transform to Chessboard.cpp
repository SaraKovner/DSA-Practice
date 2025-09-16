/*
 * You are given an n x n binary grid called board. In each move, you can swap any two rows with each other or any two columns with each other.
 * Your goal is to transform the board into a chessboard pattern.
 * A chessboard pattern is defined as a board where no two adjacent cells (horizontally or vertically) have the same value (i.e., no two 0's and no two 1's are adjacent).
 * Return the minimum number of moves required to achieve this transformation.
 * If it is impossible to transform the board into a chessboard pattern, return -1.
 * 
 * Example:
 * Input: board = [[0,1,1,0],[0,1,1,0],[1,0,0,1],[1,0,0,1]]
 * Output: 2
 * Explanation: One potential sequence of moves is shown.
 * The first move swaps the first and second column.
 * The second move swaps the second and third row.
 * If the board is:
 * [
 *   [1, 0, 1, 0],
 *   [0, 1, 0, 1],
 *   [1, 0, 1, 0],
 *   [0, 1, 0, 1]
 * ]
 * This board is also already in a chessboard pattern, so the minimum number of moves required is 0.
 * 
 * Constraints:
 * n == board.length
 * n == board[i].length
 * 2 <= n <= 30
 * board[i][j] is either 0 or 1.
 * 
 * Difficulty: 🔴 Hard
 * 
 * תרגום: מספר מהלכים מינימלי להפיכת לוח לדמקה
 * 
 * Time Complexity: O(n²) - בדיקת כל התאים בלוח
 * Space Complexity: O(1) - משתנים קבועים בלבד
 */
#include "Question.hpp"
#include "Utils.hpp"
using namespace std;

// פונקציה ראשית לחישוב מהלכים מינימליים להפיכת לוח לדמקה
// אלגוריתם: Mathematical Analysis - בדיקת תנאי הכרחיים וחישוב מהלכים
int movesToChessboard(ARR<ARR<int>> board) 
{
    int n = board.elements.size();
    
    // בדיקה 1: תנאי XOR - כל 4 פינות של כל מלבן חייבות לעמוד בתנאי XOR
    // בלוח דמקה תקף: board[0][0] ⊕ board[i][0] ⊕ board[0][j] ⊕ board[i][j] = 0
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j]) != 0)
                return -1; // לא ניתן להפוך לדמקה
                
    // בדיקה 2: ספירת 0 ו-1 בשורה ועמודה הראשונות
    int rowSum = 0, colSum = 0;
    for(int i = 0; i < n; i++)
    {
        rowSum += board[0][i]; // סכום השורה הראשונה
        colSum += board[i][0]; // סכום העמודה הראשונה
    }
    
    // בדיקה 3: תנאי איזון - מספר ה-0 וה-1 חייב להיות מאוזן
    if(n % 2 == 1) // אורך אי-זוגי
    {
        // הפרש בין 0 ל-1 חייב להיות בדיוק 1
        if(abs(n - 2*rowSum) != 1 || abs(n - 2*colSum) != 1)
            return -1;
    }
    else // אורך זוגי
    {
        // מספר ה-0 וה-1 חייב להיות שווה
        if(rowSum != n/2 || colSum != n/2)
            return -1;
    }
            
    // חישוב מספר המיקומים הלא נכונים
    int rowMis = 0, colMis = 0;
    for(int i = 0; i < n; i++)
    {
        // בדיקה אם השורה/עמודה במיקום הנכון לפי תבנית דמקה
        if(board[i][0] == i % 2) // שורה i צריכה להתחיל ב-i%2
            rowMis++;
        if(board[0][i] == i % 2) // עמודה i צריכה להתחיל ב-i%2
            colMis++;
    }
    
    // אופטימיזציה לפי זוגיות האורך
    if(n % 2 == 1) // אורך אי-זוגי
    {
        // יש רק דרך אחת נכונה - בוחרים את הדרך עם מספר זוגי של שגיאות
        if(colMis % 2 == 1)
            colMis = n - colMis;
        if(rowMis % 2 == 1)
            rowMis = n - rowMis;
    }
    else // אורך זוגי
    {
        // יש שתי דרכים אפשריות - בוחרים את המינימום
        colMis = min(colMis, n - colMis);
        rowMis = min(rowMis, n - rowMis);
    }
    
    // כל החלפה מתקנת 2 מיקומים, לכן מחלקים ב-2
    return (colMis + rowMis) / 2;
}