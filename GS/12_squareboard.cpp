// here I missunderstood the problem
// we have to consider every cell which can be the potential cell of square
class Solution
{
public:
    long long squaresInChessBoard(long long n)
    {
        // code here
        return n * (n + 1) * (2 * n + 1) / 6;
    }
};