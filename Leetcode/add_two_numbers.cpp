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
        int carry = 0;
        ListNode* temp = new ListNode(0);
        ListNode* l = temp;
        while (l1 || l2) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            if (sum > 9) {
                carry = 1;
                sum = sum % 10;
            }
            else {
                carry = 0;
            }

            l->next = new ListNode(sum);
            l = l->next;
        }
        
        if (carry) {
            l->next = new ListNode(carry);
        }
        
        return temp->next;
    }
};
