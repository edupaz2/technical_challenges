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
        ListNode* result = l1;
        // l1 and l2 are non-empty
        int sum = l1->val + l2->val;
        l1->val = sum % 10;
        int carryover = sum / 10;
        while (l1->next && l2->next) {
            l1 = l1->next;
            l2 = l2->next;
            sum = l1->val + l2->val + carryover;
            l1->val = sum % 10;
            carryover = sum / 10;
        }

        if(l1->next) {
            // l2->next is empty
            while(l1->next) {
                l1 = l1->next;
                sum = l1->val + carryover;
                l1->val = sum % 10;
                carryover = sum / 10;
            }
            if(carryover > 0) {
                ListNode* carryoverNode = new ListNode(carryover);
                l1->next = carryoverNode;
            }
        } else if (l2->next) {
            // l1->next is empty
            l1->next = l2->next; // For the result
            while(l2->next) {
                l2 = l2->next;
                sum = l2->val + carryover;
                l2->val = sum % 10;
                carryover = sum / 10;
            }
            if(carryover > 0) {
                ListNode* carryoverNode = new ListNode(carryover);
                l2->next = carryoverNode;
            }
        } else {
            // Both finished: carryover?
            if(carryover > 0) {
                ListNode* carryoverNode = new ListNode(carryover);
                l1->next = carryoverNode;
            }
        }
        return result;
    }
};
// Reference: https://leetcode.com/problems/add-two-numbers