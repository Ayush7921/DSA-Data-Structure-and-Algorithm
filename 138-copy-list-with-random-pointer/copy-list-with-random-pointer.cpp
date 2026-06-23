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
        unordered_map<Node * , Node*> mp;
        Node * temp=head;
        Node * dummy = new Node(-1);
        Node * ans = dummy;

        while(temp!=NULL){
            Node * newnode = new Node(temp->val);

            dummy->next = newnode;
            dummy = newnode;
            temp=temp->next;
        }
        Node * newtemp=ans->next;

        temp=head;
        while(temp!=NULL){
           mp[temp]=newtemp;
           temp= temp->next;
           newtemp=newtemp->next;
        }

        temp=head;
        newtemp=ans->next;
        while(temp!=NULL){
            newtemp->random = mp[temp->random];
            temp= temp->next;
            newtemp=newtemp->next;
        }

        return ans->next;


    }
};