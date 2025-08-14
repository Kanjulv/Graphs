/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node* , Node*> mp;

        Node* temp = head;

        while(temp) 
        {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp)
        {
            Node* clone = mp[temp];
            clone->next = mp[temp->next];
            clone->random = mp[temp->random];
            clone = clone->next;
            temp = temp->next;
        }

        return mp[head];
    }
};