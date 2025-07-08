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

    void reverse(ListNode* &head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next_node = nullptr;

        while (current != nullptr) {
            next_node = current->next; // Store next node
            current->next = prev;     // Reverse current node's pointer
            prev = current;           // Move pointers one position ahead
            current = next_node;
        }
        head = prev; // Update head to the new front of the list
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Handle edge cases where one or both lists are empty
        if (!l1 && !l2) {
            return nullptr; // Both lists are empty, sum is 0 (or null depending on interpretation)
        }
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        // Reverse both input lists to start addition from the least significant digit
        reverse(l1);
        reverse(l2);

        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify sum list creation
        ListNode* currentSumNode = dummyHead;
        int carry = 0;

        // Iterate while there are digits in either list or there's a carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            int digit = sum % 10;

            currentSumNode->next = new ListNode(digit);
            currentSumNode = currentSumNode->next;

            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        // The sum list is currently in reversed order (least significant digit first).
        // Reverse it back to the correct order (most significant digit first).
        // Note: The dummyHead itself is not part of the actual sum, so we reverse dummyHead->next.
        ListNode* finalResult = dummyHead->next;
        delete dummyHead; // Free the dummy head node
        
        reverse(finalResult);
        
        return finalResult;
    }
};