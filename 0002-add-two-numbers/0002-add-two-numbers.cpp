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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr_node = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        int carry = 0;
        int sum;
        
        while (temp1 != nullptr || temp2 != nullptr){
            sum = 0;
            if (temp1 == nullptr) sum += (temp2->val + carry);
            else if (temp2 == nullptr) sum += (temp1->val + carry);
            else {
                sum += (temp1->val + temp2->val + carry);
            }
            if (sum >= 10) carry = 1;
            else carry = 0;
            ListNode* new_node = new ListNode(sum % 10);
            curr_node->next = new_node; 
            curr_node = new_node;
            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }
        
        if (carry == 1){
            ListNode* new_node = new ListNode(carry);
            curr_node->next = new_node; 
            curr_node = new_node;
        }
        
        return dummy->next;
    }
};