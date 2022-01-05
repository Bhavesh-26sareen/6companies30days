// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Can simply be done by using nested loop => TC O(n^2) and SC O(1)
    // for TC O(n) and SC O(n) => we have to store the nums[i]%k freq into  map then
    // Traversing the map and checking the 3 conditions
    // 1) if ele is 0 then the freq should be even as it will form pair with itself
    // 2) if ele is k/2 then also freq must be even
    // 3) else freq of ele should be equal to freq of k-ele as both ele will form a pair

    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++)
        {
            umap[nums[i] % k]++;
        }
        for (auto m : umap)
        {
            int ele = m.first;
            int fq = m.second;

            if (ele == 0 || ele * 2 == k)
            {
                if (fq % 2 != 0)
                    return false;
            }
            else
            {
                if (fq != umap[k - ele])
                    return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} // } Driver Code Ends