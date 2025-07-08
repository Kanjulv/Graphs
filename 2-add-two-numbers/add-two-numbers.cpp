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

void reverse(ListNode* &l1)
{
    ListNode* temp = l1;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(!l1) return l2;
        if(!l2) return l1;

        int carry = 0;

        ListNode* sumNode = new ListNode(0);
        ListNode* temp = sumNode;

        while(l1 || l2 || carry != 0)
        {
            int val1 = (l1) ? l1->val : 0;
            int val2 = (l2) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;

            temp->next = new ListNode(digit);
            temp = temp->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        ListNode* final = sumNode->next;
        delete sumNode;

        return final;
    }
};