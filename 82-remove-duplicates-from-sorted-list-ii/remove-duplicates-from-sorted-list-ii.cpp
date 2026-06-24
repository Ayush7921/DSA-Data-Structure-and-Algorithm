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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){ return head;}
        ListNode * ans = new ListNode(-1);
        ans->next=head;
        ListNode * i = ans;
        ListNode * j = head;
            
            
        while(j!=NULL){
            bool duplicate = false ;
            while(  j->next!=NULL && j->val == j->next->val){
                duplicate = true;
                j=j->next;
            }
            if(duplicate){
                i->next=j->next;
            }
            else{
                i=i->next;
            }

            j=j->next;
            

        }
        return ans->next;
        
    }
};