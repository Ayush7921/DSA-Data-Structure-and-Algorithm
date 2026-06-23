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
    ListNode * findmid(ListNode* head) {
        if(head==NULL|| head->next == NULL){return head;}
        
        ListNode* s=head;
        ListNode* f=head->next;

        while(f!=NULL && f->next != NULL){
            s=s->next;
            f=f->next->next;
        }

        return s;
    }


    ListNode* merge(ListNode* l,ListNode* r){
        if(l==NULL){return r;}
        if(r==NULL){return l;}

        if(l->val<r->val){
            l->next=merge(l->next,r);
            return l;
        }else{
            r->next=merge(l,r->next);
            return r;
        }
    }
    ListNode* sortList(ListNode* head) {

        if(head== NULL || head ->next == NULL){
            return head;
        }

        ListNode * mid = findmid(head);
        ListNode * right = mid->next;
        mid->next = NULL;
        ListNode * left = head;

        ListNode * l=sortList(left);
        ListNode * r=sortList(right);

        ListNode * ans=merge(l,r);

        return ans;

        
    }
};