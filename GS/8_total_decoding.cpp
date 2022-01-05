// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // top down approach (recursion + memo) but it does not get accepted on gfg, (works on leetcode)
    /*int helper(string str , int size, vector<int> &dp , int &M)
    {
        if(dp[size] != 0) return dp[size] ;
        if(size ==0)
        {
            return 1 ;
        }
        else if(size == 1)
        {
            if(str[0]!= '0')
            return 1 ;
            return 0 ;
        }
        else
        {
            int sa1=0,sa2=0 ;
            char ch = str[0] ;
            string roq1 = str.substr(1);
            if(str[0] == '0') return 0;
            else
            {
              sa1=helper(roq1,size-1,dp,M);
            }
            string temp = str.substr(0,2) ;
            if(stoi(temp)<=26 && stoi(temp) >= 10)
            {
                 string ros2 = str.substr(2) ;
                 sa2=helper(ros2,size-2,dp,M) ;
            }
             dp[size] = (sa1+sa2)%M ;
             return dp[size];
        }

    }*/
    // Bottom-up approach (not able to write bottom up approach had to see the discussion part)
    int bottom_up(string s, int M)
    {
        int n = s.length();
        if (n == 0 || s[0] - '0' == 0)
            return 0;
        if (n == 1)
            return 1;
        int res = 0;
        int p1 = 1, p2 = 1;
        for (int i = 1; i < n; i++)
        {
            int x = s[i] - '0';
            int y = (s[i - 1] - '0') * 10 + x;
            res = 0;
            if (x > 0 && x <= 9)
                res = (res + p1) % M;
            if (y >= 10 && y <= 26)
                res = (res + p2) % M;
            p2 = p1;
            p1 = res;
        }
        return res % M;
    }
    int CountWays(string str)
    {
        // Code here
        // vector<int> dp(str.size()+5 , 0) ;
        int M = 1e9 + 7;
        // return helper(str , str.size(),dp,M) ;
        return bottom_up(str, M);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends