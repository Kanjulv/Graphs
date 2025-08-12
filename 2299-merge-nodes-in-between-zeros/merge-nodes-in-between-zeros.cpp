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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        ListNode* temp2 = dummy;

        while(temp != NULL)
        {
            if(temp->val == 0) 
            {
            temp = temp->next;
            }

            else {
                int sum = 0;
                while(temp != NULL && temp->val != 0)
                {
                    sum += temp->val;
                    temp = temp->next;
                }
                temp2->next = new ListNode(sum);
                temp2 = temp2->next;
            }
        }

        return dummy->next;
    }
};