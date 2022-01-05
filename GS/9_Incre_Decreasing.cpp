// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// similar to leetcode 456. 132 Pattern 
// } Driver Code Ends
class Solution
{
public:
   // TC O(8)~= O(1) since size of string is at max 8 and SC 2*O(8)~= O(1)   
    string printMinNumberForPattern(string s)
    {
        // code here
        string res = "";
        int c = 1;
        stack<int> st;
        for (auto ch : s)
        {
            if (ch == 'I')
            {
                st.push(c);
                c++;
                while (!st.empty())
                {
                    res += to_string(st.top());
                    st.pop();
                }
            }
            else
            {
                st.push(c);
                c++;
            }
        }
        st.push(c);
        while (!st.empty())
        {
            res += to_string(st.top());
            st.pop();
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
