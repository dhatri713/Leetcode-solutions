/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool detect_loop(ListNode* head){
        if (head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }
        return false;
    }
    
    ListNode *detectCycle(ListNode *head) {
        if (!detect_loop(head)) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* collision = nullptr;
        
        while (fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                collision = fast;
                break;
            }
        }
        
        slow = head;
        
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};