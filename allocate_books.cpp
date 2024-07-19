#include <bits/stdc++.h>

int find_max(vector<int> arr)
{
    int max = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int sum(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}

int num_students(vector<int> arr, int pages)
{
    int student = 1;
    int student_pages = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (student_pages + arr[i] <= pages)
        {
            student_pages += arr[i];
        }
        else
        {
            student += 1;
            student_pages = arr[i];
        }
    }
    return student;
}

int findPages(vector<int> &arr, int n, int m)
{
    int low = find_max(arr);
    int high = sum(arr);

    if (m > n)
        return -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int curr_num_students = num_students(arr, mid);
        if (curr_num_students <= m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}