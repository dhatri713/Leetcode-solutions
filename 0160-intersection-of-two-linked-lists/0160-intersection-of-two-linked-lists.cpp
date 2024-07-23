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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        
        while(temp1 != nullptr && temp2 != nullptr){
            len1++;
            len2++;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        while(temp1 != nullptr){
            len1++;
            temp1 = temp1->next;
        }
        
        while(temp2 != nullptr){
            len2++;
            temp2 = temp2->next;
        }
        
        cout << len1 << " " << len2 << endl;
        
        temp1 = headA;
        temp2 = headB;
        if (len1 > len2){
            int diff = len1 - len2;
            cout << diff << endl;
            //temp1 = headA;
            while (diff > 0){
                temp1 = temp1->next;
                diff--;
            }
        }
        
        else {
            int diff = len2 - len1;
            cout << diff << endl;
            //temp2 = headB;
            while (diff > 0){
                temp2 = temp2->next;
                diff--;
            }
        }
        
        cout <<"after same level" << temp1->val << " " << temp2->val << endl;
        
        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        
        return NULL;
    }
};