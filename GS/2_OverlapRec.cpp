
#include <iostream>
#include <algorithm>
using namespace std;

// Obseravtion based question
class Solution
{
public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[])
    {
        // code here
        if (min(L1[1], L2[1]) >= max(R2[1], R1[1]) && max(L2[0], L1[0]) <= min(R1[0], R2[0]))
            return 1;
        return 0;
    }
};
// 69 65 70 42 36 -25 84 -48
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
} 