Node *segregate(Node *head)
{
    // if (head == nullptr || head->next == nullptr) return head;
    // Node* mover = head;
    // int ones = 0;
    // int zeros = 0;
    // int twos = 0;

    // while (mover != nullptr){
    //     if (mover->data == 0) zeros++;
    //     else if (mover->data == 1) ones++;
    //     else twos++;
    //     mover = mover->next;
    // }

    // mover = head;
    // while (zeros > 0) {
    //     mover->data = 0;
    //     mover = mover->next;
    //     zeros--;
    // }

    // while (ones > 0) {
    //     mover->data = 1;
    //     mover = mover->next;
    //     ones--;
    // }

    // while (twos > 0) {
    //     mover->data = 2;
    //     mover = mover->next;
    //     twos--;
    // }

    // return head;

    // by changing links
    Node *mover = head;

    Node *dummy0 = new Node(-1);
    Node *mover0 = dummy0;

    Node *dummy1 = new Node(-1);
    Node *mover1 = dummy1;

    Node *dummy2 = new Node(-1);
    Node *mover2 = dummy2;

    while (mover != nullptr)
    {
        if (mover->data == 0)
        {
            mover0->next = mover;
            mover0 = mover0->next;
        }

        else if (mover->data == 1)
        {
            mover1->next = mover;
            mover1 = mover1->next;
        }

        else
        {
            mover2->next = mover;
            mover2 = mover2->next;
        }

        mover = mover->next;
    }

    mover0->next = (dummy1->next) ? (dummy1->next) : (dummy2->next);
    mover1->next = (dummy2->next);
    mover2->next = nullptr;
    head = dummy0->next;

    // free(mover0);
    free(dummy0);
    // free(mover1);
    free(dummy1);
    // free(mover2);
    free(dummy2);
    // free(mover);

    return head;
}