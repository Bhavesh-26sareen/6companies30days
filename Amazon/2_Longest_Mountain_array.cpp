// https://leetcode.com/problems/longest-mountain-in-array/
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        /* 2 1 4 7 3 2 5
          Logic :                                                  /\
        We have to find the longest subarray which is a mountain (/  \) so what we can do is maintain the             two arrays in which one array will keep the count of no. of continous increasing elements from               0th idx to (i-1)th idx for ex we have 2 1 4 7 3 2 5  then Up array will store the 0 0 1 2 0 0 1
        and down array will keep the count of num of continous increasing element form (n-1)th idx to                 (i+1)th iterating from the back ex 1 0 0 2 1 0 0
        Final Output will be the max(up[i] + down[i]+1) where (up[i] != 0 && down[i] != 0) */

        // TC : O(3*n) SC : O(2*n)

        vector<int> up(n, 0), down(n, 0);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
                up[i] = up[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
                down[i] = down[i + 1] + 1;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (up[i] != 0 && down[i] != 0)
                res = max(res, up[i] + down[i] + 1);
        }
        return res;

        // Follow up
        // Not able to do
        /*int up = 0 ;
        int down = 0 ;
        int res = 0 ;
        for(int i = 1 ; i< n ; i++)
        {

            up+= arr[i] > arr[i-1] ;
            down+= arr[i-1]>arr[i] ;
            cout<<i <<" "<<up<<" "<<down <<endl;
            if(up != 0 && down != 0) res = max(res , up + down + 1) ;

        }
        return res ;
        */
    }
};