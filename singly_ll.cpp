#include <bits/stdc++.h>
using namespace std;

// Think of all corner cases when it comes to LL
// Never tamper with the head node

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

// length of LL
int length(Node *head)
{
    int ans = 0;
    Node *mover = head;

    while (mover != NULL)
    {
        ans += 1;
        mover = mover->next;
    }

    return ans;
}

// search for element in LL
bool search(int x, Node *head)
{
    Node *mover = head;
    while (mover != NULL)
    {
        if (mover->data == x)
            return true;
        mover = mover->next;
    }
    return false;
}

// convert array to LL
Node *convert_array_to_LL(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < n; i++)
    {
        Node *new_node = new Node(arr[i]);
        mover->next = new_node;
        mover = mover->next;
    }

    return head;
}

// print elements of LL
void print_LL(Node *head)
{
    Node *mover = head;
    while (mover != nullptr)
    {
        cout << mover->data << " ";
        mover = mover->next;
    }
}

// delete at head, tail, at index k (1 based)
void delete_at_k(Node *head, int k)
{
    Node *mover = head;
    if (mover == NULL)
        return;
    if (k > length(head))
        return;
    if (k == 1)
        mover = nullptr;
}
// insert at head, tail, at index k (1 based)

int main()
{
    int arr[] = {1, 2, 3};
    Node *head = convert_array_to_LL(arr, 3);
    // print_LL(head);
    // cout << length(head);
    // cout << search(2, head);
    return 0;
}