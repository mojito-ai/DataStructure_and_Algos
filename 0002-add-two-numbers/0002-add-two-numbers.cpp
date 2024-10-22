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

    /**
    * 9 9
    * 9 9 
    * 8 9 1
    */
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);  // Dummy node to help simplify code
        ListNode* ans = new ListNode();
        ListNode* start = ans;

        while (l1 != dummy || l2 != dummy) {
            ans->val = (carry + l1->val + l2->val)%10;
            carry = (carry + l1->val + l2->val)/10;
            
            if (l1->next != nullptr || l2 -> next != nullptr) {
                ans->next = new ListNode();
                ans = ans->next;
            }

            l1 = l1->next != nullptr ? l1->next : dummy;
            l2 = l2->next != nullptr ? l2->next : dummy;
        }

        if(carry != 0) {
            ans->next = new ListNode();
            ans = ans->next;
            ans->val = carry;
        }

        return start;
    }
};