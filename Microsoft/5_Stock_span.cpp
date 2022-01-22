// NYC PROBLEM
// Monotonic stack concept used
// Maintain the decreasing stack from bottom to top
class Solution
{
public:
    // Function to calculate the span of stockâ€™s price for all n days.
    vector<int> calculateSpan(int price[], int n)
    {
        // Your code here
        vector<int> ans(n);
        stack<int> s; // Using Decreasing Stack
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && price[s.top()] <= price[i])
                s.pop();
            ans[i] = (i - (!s.empty() ? s.top() : -1));
            s.push(i);
        }
        return ans;
    }
};