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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode* temp = head;
        int size = 0;

        while(temp != NULL)
        {
            temp = temp->next;
            size++;
        }

        cout << size;

        if(size == n) return head->next;

        int count = 1;
        temp = head;

        while(temp != NULL && count < size-n)
        {
            temp = temp->next;
            count++;
        }

        temp->next = temp->next->next;

        return head;
    }
};