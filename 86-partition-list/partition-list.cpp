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
    ListNode* partition(ListNode* head, int x) {
        ListNode * ls = new ListNode(-1);
        ListNode * le=ls;
        ListNode * rs=NULL;
        ListNode * re=NULL;

        ListNode * temp = head;

        while(temp!=NULL){
            if(temp->val<x){

                le->next=temp;
                le=le->next;
                
            }
            else{
                if(rs==NULL){
                    rs=temp;
                    re=rs;
                }else{
                    re->next = temp;
                    re=re->next;
\
                }
            }
            temp=temp->next;
            le->next=NULL;
            if(re!=NULL){re->next=NULL;}
        } 

        le->next=rs;

        return ls->next;      
    }
};