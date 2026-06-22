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
    int size( ListNode* head){
        int count =0 ;
        ListNode* temp = head;
        while(temp!= NULL){
            temp=temp->next;
            count ++ ;
        }
        return count ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        if(size(head)<k){
            return head;
        }


        int count =0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;

        while(curr!=NULL && count < k){
            forw=curr->next;
            curr->next  = prev;
            prev = curr ;
            curr = forw ;
            count++ ;
        }

        if(forw!=NULL){
            head->next=reverseKGroup(forw,k);
        }

        return prev;
    }
};