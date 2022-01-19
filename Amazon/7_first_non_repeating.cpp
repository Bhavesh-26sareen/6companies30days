// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        string ans = "";
        // Code here
        vector<int> v(26, 0);
        int n = A.length();

        queue<char> q;
        for (int i = 0; i < n; i++)
        {
            if (v[A[i] - 'a'] == 0)
            {
                q.push(A[i]);
                v[A[i] - 'a']++;
            }
            else
            {
                v[A[i] - 'a']++;
                while (!q.empty() && v[q.front() - 'a'] > 1)
                    q.pop();
            }
            if (q.empty())
            {
                ans.push_back('#');
            }
            else
                ans.push_back(q.front());
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends