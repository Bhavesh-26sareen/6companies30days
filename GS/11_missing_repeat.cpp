class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int *temp = new int[2];
        int rele = 0, mele = 0;
        for (int i = 0; i < n; i++)
        {
            int idx = abs(arr[i]) - 1;
            if (arr[idx] > 0)
            {
                arr[idx] = -1 * arr[idx];
            }
            else
            {
                rele = abs(arr[i]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
                mele = i + 1;
        }
        temp[0] = rele;
        temp[1] = mele;
        return temp;
    }
};