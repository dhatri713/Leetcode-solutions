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
        if (head == nullptr || (head->next == nullptr && n == 1)) return nullptr;
        if (n == 0) return head;
        int length = 0;
        ListNode* mover = head;
        while(mover != nullptr){
            length++;
            mover = mover->next;
        }
        
        mover = head;
        
        if (length == n){
            head = head->next;
            delete mover;
            return head;
        }
        
        int cnt = (length - n);
        while (cnt > 1){
            mover = mover->next;
            cnt--;
        }
        ListNode* temp = (mover->next) ? mover->next : nullptr;
        mover->next = (temp->next) ? temp->next : nullptr;
        delete temp;
        return head;
    }
};