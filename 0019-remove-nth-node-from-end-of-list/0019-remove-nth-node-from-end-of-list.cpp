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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // brute force 
        
//         if (head == nullptr || (head->next == nullptr && n == 1)) return nullptr;
//         if (n == 0) return head;
//         int length = 0;
//         ListNode* mover = head;
//         while(mover != nullptr){
//             length++;
//             mover = mover->next;
//         }
        
//         mover = head;
        
//         if (length == n){
//             head = head->next;
//             delete mover;
//             return head;
//         }
        
//         int cnt = (length - n);
//         while (cnt > 1){
//             mover = mover->next;
//             cnt--;
//         }
//         ListNode* temp = (mover->next) ? mover->next : nullptr;
//         mover->next = (temp->next) ? temp->next : nullptr;
//         delete temp;
//         return head;
        
        // optimal - using slow and fast pointers
        if (head == nullptr || (head->next == nullptr && n == 1)) return nullptr;
        if (n == 0) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        int cnt = n;
        
        while (cnt > 0){
            fast = fast->next;
            cnt --;
        }
        
        if (fast == nullptr){
            head = head->next;
            delete fast;
            delete slow;
            return head;
        }
        
        while (fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        // delete fast;
        // delete slow;
        return head;
    }
};