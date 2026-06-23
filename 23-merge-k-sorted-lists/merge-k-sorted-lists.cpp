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
    ListNode* merge( ListNode* l , ListNode* r){
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        int n= lists.size();
        if(n==0){return NULL;}
        if(n==1){return lists[0];}
        ListNode * result=lists[0];
        for(int i=1;i<n;i++){
            result=merge(result,lists[i]);
        }

        return result;      
    }
};