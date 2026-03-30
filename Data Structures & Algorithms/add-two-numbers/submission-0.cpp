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
        
        ListNode dummy(0);
        ListNode* r = &dummy;
        ListNode* a = l1;
        ListNode* b = l2;
        int carry = 0;

        while ((a || b) || carry > 0)
        {
            int av = (a) ? a->val : 0;
            int bv = (b) ? b->val : 0;
            int sum = av + bv + carry;

            int dig = sum % 10;
            carry = sum / 10;
            
            r->next = new ListNode(dig);
            r = r->next;

            if (a) a = a->next;
            if (b) b = b->next;
        }

        cout << carry;

        return dummy.next;
    }
};
