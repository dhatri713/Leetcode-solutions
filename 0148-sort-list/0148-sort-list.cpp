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
    ListNode* sortList(ListNode* head) {
        multiset<int> nums;
        ListNode* mover = head;
        while (mover != nullptr){
            nums.insert(mover->val);
            mover = mover->next;
        }
        mover = head;
        auto it = nums.begin();
        while (mover != nullptr){
            mover->val = *it;
            mover = mover->next;
            it++;
        }
        
        return head;
    }
};