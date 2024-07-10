#include <bits/stdc++.h>
using namespace std;

int brute_force(vector<int> nums, int k)
{
    int max_len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < nums.size(); j++)
        {
            sum += nums[j];
            if (sum == k)
            {
                int curr_len = j - i + 1;
                max_len = max(curr_len, max_len);
            }
        }
    }
    return max_len;
}

// cannot be optimzied further if the array has positives, zeroes and negatives
int prefix_sum(vector<int> nums, int k)
{
    map<int, int> prefixes;
    int sum = 0;
    int max_len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            max_len = max(max_len, i + 1);
        }

        if (prefixes.find(sum) == prefixes.end())
        {
            prefixes[sum] = i;
        }
        int rem_sum = sum - k;
        if (prefixes.find(rem_sum) != prefixes.end())
        {
            int len = i - prefixes[rem_sum];
            max_len = max(max_len, len);
        }
    }
    return max_len;
}

// can be optimized if the array has only postives
// two pointer

int two_pointer(vector<int> nums, int k)
{
    int i = 0;
    int max_len = 0;
    int sum = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];

        while (sum > k && i <= j)
        {
            sum -= nums[i];
            i++;
        }

        if (sum == k)
        {
            max_len = max(max_len, j - i + 1);
        }
    }
    return max_len;
}

int main()
{
    vector<int> nums = {1, 2, 1, 3};
    cout << two_pointer(nums, 2);
    return 0;
}