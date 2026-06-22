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
    ListNode* rotateRight(ListNode* head, int k) {

        int size= 0;
        ListNode * temp = head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }

        if(k==0 || head==NULL || head->next == NULL){
            return head;
        }
        k=k%size;
        if(k==0){return head;}

        int cnt = 0;
        ListNode * prev = NULL;
        ListNode * curr = head;

        while(cnt < size-k){

            prev = curr;
            curr=curr->next ;
            cnt++;
        }
        ListNode * ans=curr;
        prev->next = NULL ;

        while(curr->next!=NULL){
            curr=curr->next;
        }

        curr->next =head;
        return ans;
        
    }
};