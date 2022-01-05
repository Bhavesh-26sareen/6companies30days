// very nyc concept of Binary search(on answer) + sliding window
// Must see question
class Solution
{
public:
    bool check(vector<int> &nums, int k, int midlen)
    {
        int i = 0;
        int j = 0;
        int n = nums.size();
        long long sum = 0;
        while (j < n)
        {
            sum += nums[j];
            // cout<<"sum "<<sum << "j: "<<j<<endl;
            if (sum >= k)
                return true;
            if (j - i + 1 < midlen)
                j++;
            else if (j - i + 1 == midlen)
            {
                if (sum >= k)
                    return true;
                sum -= nums[i];
                // cout<<"s " <<sum<<endl;
                // if(sum >= k) return true ;
                i++;
                j++;
            }
        }
        return false;
    }
    int minSubArrayLen(int k, vector<int> &nums)
    {
        int start = 1;
        int end = nums.size();
        // cout<<end<<endl;
        while (end - start > 1)
        {
            int mid = start + (end - start) / 2;
            cout << mid << endl;

            if (check(nums, k, mid))
                end = mid;
            else
            {

                start = mid + 1;
            }
        }

        if (check(nums, k, start))
        {
            if (start == 0)
                return 1;
            return start;
        }
        else if (check(nums, k, end))
            return end;
        return 0;
    }
};