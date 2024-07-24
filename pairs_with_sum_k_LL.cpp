//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

// } Driver Code Ends
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node *left = head;
        Node *right = head;
        vector<pair<int, int>> ans;
        while (right->next != nullptr)
            right = right->next;

        while (left->data < right->data)
        {
            int curr_sum = left->data + right->data;
            if (curr_sum == target)
            {
                pair<int, int> pair_ = {left->data, right->data};
                ans.push_back(pair_);
                left = left->next;
                right = right->prev;
            }
            else if (curr_sum > target)
                right = right->prev;
            else
                left = left->next;
        }

        // if (left->data * 2 == target){
        //     pair<int, int> pair_= {left->data, right->data};
        //     ans.push_back(pair_);
        // }

        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends