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
    ListNode * reverse (ListNode* &head){
        if(head==NULL|| head->next == NULL){
            return head;
        }

        ListNode* curr=head;
        ListNode* prev = NULL;
        ListNode* forw = NULL;
        while(curr!=NULL){
            forw=curr->next;
            curr->next = prev;
            prev = curr;
            curr= forw;
        }

        return prev;

    }
    void reorderList(ListNode* head) {
        if(head == NULL || head ->next ==NULL || head->next ->next == NULL){return;}
        
        ListNode * s=head;
        ListNode * f = head->next;
        while(f !=NULL && f ->next !=NULL){
            s=s->next;
            f=f->next->next;
        }

        ListNode * r = reverse(s->next);
        s->next=NULL;
        ListNode * l = head;
        ListNode * ans = new ListNode(-1);
        ListNode * temp = ans;
        while(l!=NULL && r!=NULL){
            temp->next=l;
            temp=l;
            l=l->next;

            temp->next=r;
            temp=r;
            r=r->next;
            

        }
        temp->next = l;

        ans=ans->next;
        head=ans;



    }
};