/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <algorithm>

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Step 1: Find the middle of the linked list using slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        // Step 3: Iterate through both halves to find the maximum twin sum
        int maxTwinSum = 0;
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev; // 'prev' is the new head of the reversed second half
        
        while (secondHalf != nullptr) {
            maxTwinSum = std::max(maxTwinSum, firstHalf->val + secondHalf->val);
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        return maxTwinSum;
    }
};