// Same as Leetcode Buy and sell 4
// Approach : Recursion + Memo

// TC = O(k*n) and SC = O(2*k*n) where n = arr.size() and k is no. of transactions
class Solution
{
public:
    int dp[100005][2][105];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }
    int helper(vector<int> &prices, int idx, int state, int trans, int k)
    {
        if (idx >= prices.size() || trans >= k)
            return 0;
        if (dp[idx][state][trans] != -1)
            return dp[idx][state][trans];
        int skip = helper(prices, idx + 1, state, trans, k);
        int res;
        if (state == 0)
        {
            res = -prices[idx] + helper(prices, idx + 1, !state, trans, k);
        }
        else
            res = prices[idx] + helper(prices, idx + 1, !state, trans + 1, k);
        return dp[idx][state][trans] = max(skip, res);
    }

    int maxProfit(int k, vector<int> &prices)
    {
        // 3 3 5 0 0 3 1 4
        return helper(prices, 0, 0, 0, k);
    }
};