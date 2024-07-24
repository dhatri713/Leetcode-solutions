/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
//         unordered_map<Node*, Node*> mpp;
//         Node* temp = head;
//         while (temp != nullptr){
//             Node* new_node = new Node(temp->val);
//             mpp[temp] = new_node;
//             temp = temp->next;
//         }
        
//         temp = head;
//         while (temp != nullptr){
//             Node* next = mpp[temp->next];
//             Node* random = mpp[temp->random];
//             mpp[temp]->next = next;
//             mpp[temp]->random = random;
//             temp = temp->next;
//         }
//         return mpp[head];
        
        Node* temp = head;
        while (temp != nullptr){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        
        temp = head;
        while (temp != nullptr){
            if (temp->random == nullptr) temp->next->random = nullptr;
            else {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;
        while (temp != nullptr){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        
        return dummy->next;
    }
};