//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        vector<int> how_many_placed(stations.size() - 1, 0);
        // brute force

        // for (int gas_stations = 1; gas_stations <= k; gas_stations++){
        //     double max_length = -1;
        //     int max_length_ind = -1;
        //     for (int i = 0; i < stations.size() - 1; i++){
        //         double section_length = static_cast<double>(stations[i + 1] - stations[i])/(how_many_placed[i] + 1);
        //         if (section_length > max_length){
        //             max_length = section_length;
        //             max_length_ind = i;
        //         }
        //     }
        //     how_many_placed[max_length_ind]++;
        // }

        // double answer = -1;

        // for (int i = 0; i < stations.size() - 1; i++){
        //         double section_length = static_cast<double>(stations[i + 1] - stations[i])/(how_many_placed[i] + 1);
        //         answer = max(section_length, answer);
        // }

        // return answer;

        // using priority queue

        // priority_queue<pair<double, int>> pq;

        // for (int i = 0; i < stations.size() - 1; i++){
        //     double section_len = static_cast<double>(stations[i + 1] - stations[i])/(how_many_placed[i] + 1);
        //     pq.push({section_len, i});
        // }

        // for (int gas_stations = 1; gas_stations <= k; gas_stations++) {
        //     auto tp = pq.top();
        //     pq.pop();
        //     int section_ind = tp.second;
        //     how_many_placed[section_ind]++;
        //     double new_section_len = static_cast<double>(stations[section_ind + 1] - stations[section_ind])/(how_many_placed[section_ind] + 1);
        //     pq.push({new_section_len, section_ind});
        // }

        // return pq.top().first;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++)
        {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends