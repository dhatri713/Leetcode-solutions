//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to find square root
// x: element to find square root
#include <bits/stdc++.h>
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        long long int low = 1;
        long long int high = x;
        long long int answer = 1;

        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            long long int curr_answer = mid;

            if (curr_answer * curr_answer <= x)
            {
                answer = max(answer, curr_answer);
                low = mid + 1;
            }

            else
                high = mid - 1;
        }

        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends