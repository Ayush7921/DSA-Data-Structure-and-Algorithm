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
    ListNode* removeElements(ListNode* head, int val) {

        if(head == NULL ){return head;}
        
        ListNode * dummy = new ListNode (-1);
        ListNode * prev = dummy;
        prev->next = head;
        ListNode * curr = head ;

        while(curr!=NULL ){
              
            while(curr!= NULL && curr->val == val){
                prev->next = curr->next;
                curr=curr->next;
            }

            prev=curr;
            if(curr!=NULL){
            curr= curr->next; }
            

        }
        return dummy ->next;
    }
};