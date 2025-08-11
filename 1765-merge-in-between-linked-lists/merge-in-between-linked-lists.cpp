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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        int count1 = 1, count2 = 1;
        ListNode* temp = list1;
        ListNode* next = list1;

        //Placing temp at a-1;
        while(temp != NULL && count1 < a)
        {
            temp = temp->next;
            count1++;
        }

        //Placing next at b-1;
        while(next != NULL && count2 <= b+1)
        {
            next = next->next;
            count2++;
        }

        temp->next = list2;
        temp = list2;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = next;

        return list1;
        
    }
};