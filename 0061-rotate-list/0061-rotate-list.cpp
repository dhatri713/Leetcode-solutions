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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        int length = 0;
        while (temp != nullptr){
            length++;
            temp = temp->next;
        }
        
        int num_rotations = k % length;
        if (num_rotations == 0) return head;
        
        //if (num_rotations == length - 1) num_rotations = 0;
        temp = head;
        int cnt = 1;
        while (temp != nullptr){
            if (cnt == (length - num_rotations)) break;
            temp = temp->next;
            cnt++;
        }
        
        ListNode* new_head = temp->next;
        ListNode* temp2 = new_head;
        while (temp2->next != nullptr)temp2 = temp2->next;
        temp2->next = head;
        head = new_head;
        temp->next = nullptr;
        return head;
    }
};