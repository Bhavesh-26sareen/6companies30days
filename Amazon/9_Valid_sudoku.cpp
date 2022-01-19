// Main tricky part here is finding the smaller matrix from rows and cols
// which is i/3 * 3 + j/3
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, set<int>> row, col, sm;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (row[i].count(board[i][j]))
                {

                    return false;
                }
                row[i].insert(board[i][j]);
                int x = i / 3 * 3 + j / 3;
                if (sm[x].count(board[i][j]))
                {

                    return false;
                }
                sm[x].insert(board[i][j]);
            }
        }

        for (int j = 0; j < 9; j++)
        {
            for (int i = 0; i < 9; i++)
            {
                if (board[i][j] == '.')
                    continue;
                if (col[j].count(board[i][j]))
                    return false;
                col[j].insert(board[i][j]);
            }
        }
        return true;
    }
};
