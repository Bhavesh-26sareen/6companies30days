#include <bits/stdc++.h>
using namespace std;
// Approach :- Sliding Window
// TC O(n) , SC O(1)
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0;
    int j = 0;
    long long pro = 1;
    int count = 0;
    while (j < n)
    {
        pro = pro * a[j];
        if (pro < k)
        {
            count += j - i + 1;
            j++;
        }
        else
        {
            while (pro >= k)
            {

                pro = pro / a[i++];
            }
            count += j - i + 1;
            j++;
        }
    }
    cout << count;
    return 0;
}
