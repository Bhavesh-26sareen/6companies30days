// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // TC O(len(s)) and  SC O(len(s)) ;
    string decodedString(string s)
    {
        // code here
        stack<string> st;
        stack<int> fq;
        string curr = "";
        string digit = "";
        for (auto ch : s)
        {
            if (isdigit(ch))
                digit += ch;
            else if (isalpha(ch))
                curr += ch;
            else if (ch == '[')
            {
                st.push(curr);
                fq.push(stoi(digit));
                curr = "";
                digit = "";
            }
            else
            {
                int d = fq.top();
                fq.pop();
                string temp = curr;
                curr = st.top();
                st.pop();
                for (int i = 0; i < d; i++)
                    curr += temp;
            }
        }
        return curr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";
    }
    return 0;
} // } Driver Code Ends