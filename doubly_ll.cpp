#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

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

Node *convert_arr_to_dll(int arr[], int n)
{
    if (n == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < n; i++)
    {
        Node *new_node = new Node(arr[i]);
        new_node->back = mover;
        mover->next = new_node;
        mover = new_node;
    }
    return head;
}

Node *delete_head(Node *head)
{
    Node *mover = head;
    if (mover == NULL || mover->next == nullptr)
        return nullptr;
    else
    {
        head = mover->next;
        head->back == nullptr;
        mover->next == nullptr;
        free(mover);
        return head;
    }
}

Node *delete_tail(Node *head)
{
    Node *prev = head;
    if (prev == NULL || prev->next == nullptr)
        return nullptr;
    while (prev->next->next != nullptr)
    {
        prev = prev->next;
    }
    Node *temp = prev->next;
    prev->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return head;
}

Node *delete_at_k(Node *head, int k)
{
    if (head == NULL)
        return nullptr;
    else if (k > length(head))
        return head;
    else if (k == 1)
        return delete_head(head);
    else if (k == length(head))
        return delete_tail(head);
    int cnt = 0;
    Node *mover = head;
    while (cnt < k)
    {
        mover = mover->next;
    }
    Node *prev = mover->back;
    prev->next = mover->next;
    mover->next->back = prev;
    mover->next = nullptr;
    mover->back = nullptr;
    delete mover;
    return head;
}

void delete_node(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
    return;
}

Node *insert_at_head(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *mover = head;
    Node *new_node = new Node(val);
    new_node->next = mover;
    new_node->back = nullptr;
    mover->back = new_node;
    return new_node;
}

int main()
{
    return 0;
}