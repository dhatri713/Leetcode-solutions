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
    ListNode* reverse(ListNode *head) {
    ListNode* prev = NULL;
    while (head != NULL) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* find_kth_node(ListNode* head, int k) {
    while (head != NULL && k > 1) {
        head = head->next;
        k--;
    }
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (head == NULL || k == 1) return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* group_prev = dummy;
    
    while (true) {
        ListNode* kth = find_kth_node(group_prev->next, k);
        if (kth == NULL) break;
        
        ListNode* group_next = kth->next;
        
        // Reverse the group
        ListNode* prev = group_next;
        ListNode* curr = group_prev->next;
        while (curr != group_next) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        // Adjust the pointers
        ListNode* temp = group_prev->next;
        group_prev->next = kth;
        group_prev = temp;
    }
    
    return dummy->next;
}
};