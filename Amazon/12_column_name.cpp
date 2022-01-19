class Solution
{
public:
    string colName(long long int n)
    {
        // your code here
        // cout << 4294967295 % 26 ;

        string ans = "";
        
        while (n != 0)
        {
            char ch = ('A' + ((n - 1) % 26));
            ans = ch + ans;
            n = (n - 1) / 26;
        }

        return ans;
    }
};