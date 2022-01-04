#include <bits/stdc++.h>
using namespace std;
// ugly number is that whose prime factors are 2,3 and 5
// return the nth ugly number
unsigned long long uglynumber(int n)
{
    // 1st Approach using sets TC O(nlogn) SC O(n)
    /*
     set<int> s ;
     s.insert(1) ;
     unsigned long long ans;
     while(n--)
     {
         ans = *s.begin() ;
         s.erase(ans) ;
         s.insert(ans*2) ;
         s.insert(ans*3) ;
         s.insert(ans*5) ;
     }
     return ans ;
     */
    // 2nd Approach using DP TC O(n) SC O(n) ;
    vector<unsigned long long> temp(n + 1);
    temp[0] = 1;
    unsigned long long v2 = 2, v3 = 3, v5 = 5;
    unsigned long long nxt = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; i++)
    {
        nxt = min(v2, min(v3, v5));
        temp[i] = nxt;
        if (nxt == v2)
        {
            i2++;
            v2 = temp[i2] * 2;
        }
        if (nxt == v3)
        {
            i3++;
            v3 = temp[i3] * 3;
        }
        if (nxt == v5)
        {
            i5++;
            v5 = temp[i5] * 5;
        }
    }
    return nxt;
}
int main()
{
    int n;
    cin >> n;
    cout << uglynumber(n);
    return 0;
}