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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* split = head;

        while (split && count < k)
        {
            split = split->next;
            count++;
        }

        if (count < k) return head;
        
        ListNode* start = head;
        ListNode* prev = nullptr;
        while (start != split)
        {
            ListNode* temp = start->next;
            start->next = prev;
            prev = start;
            start = temp; 
        }

        head->next = reverseKGroup(split, k);
        return prev;

    }
};
