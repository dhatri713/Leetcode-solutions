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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* temp1 = head;
        if (temp1 == nullptr || temp1->next == nullptr || temp1->next->next == nullptr) return temp1;
        // there are more than 2 in the LL
        ListNode* temp2 = head->next;
        ListNode* dummy2 = temp2;
        ListNode* dummy1 = temp1; 
        
        while (temp2 != nullptr && temp2->next != nullptr){
            temp1->next = temp2->next;
            temp2->next = temp1->next->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        temp1->next = dummy2;
        
        return dummy1;
        
    }
};