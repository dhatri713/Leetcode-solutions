// Node* reverse_list(Node* head){
//     if (head == nullptr || head->next == nullptr) return head;
//     Node* prev = nullptr;
//     Node* temp = head;

//     while (temp != nullptr){
//         Node* front = temp->next;

//         temp->next = prev;
//         prev = temp;
//         temp = front;
//     }

//     return prev;
// }

int helper(Node *temp)
{
    if (temp == nullptr)
        return 1;
    int carry = helper(temp->next);
    temp->data += carry;
    if (temp->data < 10)
        return 0;
    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    // BRUTE
    // Node* new_head = reverse_list(head);

    // int carry = 0;
    // new_head->data = (new_head->data + 1) % 10;
    // carry = ((new_head->data + 1) / 10);

    // //cout << carry << endl;
    // //cout << new_head->data << endl;

    // if (carry == 0) return reverse_list(new_head);

    // Node* temp1 = new_head->next;
    // while(temp1 != nullptr){
    //     temp1->data = (temp1->data + carry) % 10;
    //     carry = temp1->data / 10;
    // }

    // if (carry == 1){
    //     Node* new_node = new Node(carry);
    //     temp1->next = new_node;
    // }

    // return reverse_list(new_head);
    int final_carry = helper(head);
    if (final_carry == 1)
    {
        Node *new_node = new Node(1);
        new_node->next = head;
        return new_node;
    }

    return head;
}