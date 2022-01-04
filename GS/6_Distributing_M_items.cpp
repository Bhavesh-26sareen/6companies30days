#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (m > n)
        m = m % n;
    m--;
    int res;
    if ((k + m) > n)
        res = (k + m) % n;
    else
        res = (k + m);
    cout << res;
    return 0;
}