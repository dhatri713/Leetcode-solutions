/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // ITERATIVE
//         if (head == nullptr || head->next == nullptr) return head;
//         ListNode* prev = nullptr;
//         ListNode* temp = head;
//         ListNode* dummy = temp;
        
//         while (temp != nullptr){
//             ListNode* front = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp = front;
//         }
        
//         return prev;
        
        // RECURSIVE
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* new_head = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return new_head;
        
    }
};