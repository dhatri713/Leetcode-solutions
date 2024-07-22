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
    
    ListNode* reverseLL(ListNode* head){
        if (head == nullptr || head->next == nullptr)return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reverse_head = (slow->next) ? (slow->next) : nullptr;
        ListNode* end_head = reverseLL(reverse_head);
        
        ListNode* temp1 = head;
        ListNode* temp2 = end_head;
        
        while (temp2 != nullptr){
            if (temp1->val == temp2->val) {
                temp1 = temp1->next;
                temp2 = temp2->next;
                continue;
            }
            else return false;
        }
        
        return true;
    }
};