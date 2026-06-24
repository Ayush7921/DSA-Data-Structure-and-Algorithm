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
    ListNode* insertionSortList(ListNode* head) {
        
    // if (!head || !head->next) {
    //         return head;
    //     }

    //     // Create a dummy node to act as the start of the sorted list
    //     ListNode* dummy = new ListNode(0);
    //     ListNode* curr = head;

    //     while (curr != nullptr) {
    //         // Save the next node to process before we detach 'curr'
    //         ListNode* nextNode = curr->next;

    //         // Start searching from the beginning of the sorted list
    //         ListNode* prev = dummy;
    //         while (prev->next != nullptr && prev->next->val < curr->val) {
    //             prev = prev->next;
    //         }

    //         // Insert curr between prev and prev->next
    //         curr->next = prev->next;
    //         prev->next = curr;

    //         // Move to the next node in the original list
    //         curr = nextNode;
    //     }

    //     ListNode* sortedHead = dummy->next;
    //     delete dummy; // Clean up memory for the dummy node
    //     return sortedHead;

        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* dummy = new ListNode(-1);
      
        // ListNode * prev = dummy;
        ListNode * curr = head;
        // ListNode * forw = NULL;


        while(curr!=NULL){

            ListNode * forw=curr->next;

            ListNode * prev = dummy ;

            while( prev->next != NULL && prev->next->val < curr->val){
               prev= prev->next;
            }
             
            curr->next = prev ->next ;
            prev ->next =curr;
            curr=forw;
            
        }

        return dummy->next;




    }
};