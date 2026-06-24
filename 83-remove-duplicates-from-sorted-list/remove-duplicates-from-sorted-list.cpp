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
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        
        ListNode * i = head;
        ListNode * j = head->next;

        while(j!=NULL){
            while(j!=NULL && j->val==i->val){
                j=j->next;
            }

            i->next=j;

            if(j!=NULL){
                i=i->next;
                j=j->next;
            }
        }
        return head;

    }
};