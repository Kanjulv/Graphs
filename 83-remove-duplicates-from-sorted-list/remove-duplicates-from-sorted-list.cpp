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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Start with a pointer at the head of the list.
        ListNode* current = head;

        // Traverse until we or the next node is null.
        while (current != nullptr && current->next != nullptr) {
            // Check if the next node is a duplicate.
            if (current->val == current->next->val) {
                // It's a duplicate, so bypass the next node.
                // current->next now points to the node after the duplicate.
                current->next = current->next->next;
            } else {
                // Not a duplicate, so move to the next node.
                current = current->next;
            }
        }
        
        return head;
    }
};