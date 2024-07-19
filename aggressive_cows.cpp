#include <bits/stdc++.h>
using namespace std;
bool can_place_cows(vector<int> arr, int num_cows, int min_dist)
{
    int cnt_cows = 1;
    int last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (min_dist <= arr[i] - last)
        {
            cnt_cows++;
            last = arr[i];
        }
        else
        {
            break;
        }
    }
    return (cnt_cows >= num_cows);
}

int min_distance(vector<int> &arr, int num_cows)
{
    sort(arr.begin(), arr.end());
    int low = 1;
    int high = arr[arr.size() - 1] - arr[0];
    int answer;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (can_place_cows(arr, num_cows, mid))
        {
            answer = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return answer;
}

int main()
{
    vector<int> arr = {0, 3, 4, 7, 9, 10};
    cout << min_distance(arr, 4);
    return 0;
}